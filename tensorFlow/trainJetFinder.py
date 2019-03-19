#!/usr/local/bin/python3
# create_model.py

import numpy as np
import configparser
import tensorflow as tf
from tensorflow.keras import optimizers
from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.layers import Add, Concatenate, Lambda
from tensorflow.keras.models import Model
from tensorflow.keras.backend import int_shape
from itertools import permutations
from itertools import combinations
from tensorflow.keras.utils import plot_model
from tensorflow.keras.callbacks import EarlyStopping
import matplotlib.pyplot as plt
import sys
sys.path.insert(0, '/Users/Liby/work/tools/frugally-deep/keras_export')
import convert_model

def isfloat(value):
  try:
    float(value)
    return True
  except ValueError:
    return False

def mean(data):
    """Return the sample arithmetic mean of data."""
    n = len(data)
    if n < 1:
        raise ValueError('mean requires at least one data point')
    return sum(data)/float(n) # in Python 2 use sum(data)/float(n)


def _ss(data):
    """Return sum of square deviations of sequence data."""
    c = mean(data)
    ss = sum((x-c)**2 for x in data)
    return ss


def stddev(data, ddof=0):
    """Calculates the population standard deviation
    by default; specify ddof=1 to compute the sample
    standard deviation."""
    n = len(data)
    if n < 2:
        raise ValueError('variance requires at least two data points')
    ss = _ss(data)
    pvar = ss/(n-ddof)
    return pvar**0.5


def readfiles(filename):
    with open(filename) as f:
        return [ [num for num in [float(s) for s in line.split(" ")[1:] if s.strip() and isfloat(s)]] for line in f]

def distribute(ibasket, baskets, remain, combo, tmpcombo):
	if ibasket==len(baskets)-1 :
		if remain<=baskets[ibasket]:
			tmpcombo[ibasket] = remain
			combo.append(tmpcombo.copy())
	else:
		if remain==0:
			tmpcombo[ibasket] = 0
			distribute(ibasket+1, baskets, remain, combo, tmpcombo)
		else:
			for x in range(0,min(remain,baskets[ibasket])+1):
				tmpcombo[ibasket] = x
				distribute(ibasket+1, baskets, remain - x, combo, tmpcombo)

def commutation(ibaskets, baskets, pick, picksum, combotmp,combo):
	if ibaskets != len(baskets):
		for x in permutations(baskets[ibaskets],pick[ibaskets]):
			for i in range(0,len(list(x))):
					combotmp[i+picksum[ibaskets]] = list(x)[i]
			commutation(ibaskets+1, baskets, pick, picksum, combotmp, combo)
	else:
		combo.append(combotmp.copy())

#=========================================configs=========================================
config = configparser.ConfigParser()
if len(sys.argv) != 2:
	print("please feed the config file")
	exit
config.read(sys.argv[1])
maxCombUnitpool = int(config['DEFAULT']['maxCombUnitpool'])
maxCombUnitwatcher = int(config['DEFAULT']['maxCombUnitwatcher'])
unitDim = int(config['DEFAULT']['unitDim'])
pool = int(config['DEFAULT']['pool'])
watchers = [int(x) for x in config['DEFAULT']['watchers'].split(',')]
outputcategory = int(config['DEFAULT']['outputcategory'])
modelname = config['DEFAULT']['modelname']

#=========================================construct inputs=========================================
nobj = 0
for x in watchers:
	nobj+=x
nwatcies = nobj
nobj+=pool

watcherstartindex = []
watcherstartindex.append(pool)
for i in range(0,len(watchers)-1):
	watcherstartindex.append(watcherstartindex[i]+watchers[i])


watchersobjtmp=[]
watchersobj=[]

for i in range(0,len(watchers)):
	for x in range(0,watchers[i]):
		watchersobjtmp.append(watcherstartindex[i]+x)
	watchersobj.append(watchersobjtmp.copy())
	watchersobjtmp.clear()


inputs = []
for input in range(0,nobj):
	inputs.append(Input(shape=(unitDim,)))
nodepool = []
nodepool1 = []
nodepool2 = []
nodewatcher = []
nodewatcher1 = []
nodewatcher2 = []
for nnodepool in range(2,maxCombUnitpool+1):
	nodepool.append(Dense(8,input_dim=unitDim, activation= 'sigmoid'))
	nodepool1.append(Dense(8,input_dim=unitDim, activation='sigmoid'))
	nodepool2.append(Dense(8,input_dim=unitDim, activation='sigmoid'))
poolarray = []
poolarrayn= []
watcherarray = []
#c_pooln
c_pool = []
c_inpool=[]			
fullcombo = []

for n in range(0,maxCombUnitpool-1):
#=========================================first layer:input, pool=========================================
	ncombi = n+2
	c_pool.append([list(x) for x in list(combinations(list(range(0,pool)),ncombi))])
	for a in c_pool[-1]:
		firstiter = 1;
		ncb = 1
		for b in list(permutations(list(a))):
			ncb = 1
			if firstiter == 1:
				ele = nodepool[n](Concatenate(1)([inputs[x] for x in b]))
				firstiter = 0;
			else:
				ele = Add()([nodepool[n](Concatenate(1)([inputs[x] for x in b])), ele])
				ncb += 1

		poolarrayn.append(nodepool2[n](nodepool1[n](ele)))
	poolarray.append(poolarrayn.copy())
	poolarrayn.clear()
#=========================================first layer:input, watcher=========================================
for n in range(0,maxCombUnitwatcher-1):
	ncombi = n+2
	for ninpool in range(1,ncombi):
		ninwatcher = ncombi-ninpool
		firstiter = 1;
		c_inwtch = []
		tmpcombo = []
		for tmp in range(0,len(watchers)):
			tmpcombo.append(0)
		distribute(0,watchers,ninwatcher,c_inwtch,tmpcombo)
		wtchcombo = []
		for ele in c_inwtch: #ele=[0,0,8,0]...
			tmpcombo.clear()
			combo=[]
			for tmp in range(0,ninwatcher):
				tmpcombo.append(0)
			commutation(0, watchersobj, ele, ([0]+list(np.cumsum(ele)))[:-1], tmpcombo, combo)
			tmpcombo.clear()
			tmpcombo = []
			for ele1 in combo:
				tmpcombo.append(ele1)
			wtchcombo.append(tmpcombo.copy())
		fullcombotmp2 = []
		fullcombotmp1 = []
		watcherarraytmp = []
		for concwatc in wtchcombo:
			nodewatcher.append(Dense(7,input_dim=unitDim, activation= 'sigmoid'))
			nodewatcher1.append(Dense(7,input_dim=unitDim, activation='sigmoid'))
			nodewatcher2.append(Dense(7,input_dim=unitDim, activation='sigmoid'))
			for cinpool in list(combinations(list(range(0,pool)),ninpool)):
				firstiter = 1;
				for addwatc in concwatc:
					for perminpool in list(permutations(list(cinpool))):
						fullcombotmp1.append(list(perminpool)+addwatc)
						ncb = 1
						if firstiter == 1:
							ele = nodewatcher[-1](Concatenate(1)([inputs[x] for x in fullcombotmp1[-1]]))
							firstiter = 0;
						else:
							ele = Add()([nodewatcher[-1](Concatenate(1)([inputs[x] for x in fullcombotmp1[-1]])), ele])
							ncb += 1

				watcherarraytmp.append(nodewatcher2[-1](nodewatcher1[-1](ele)))
				fullcombotmp2.append(fullcombotmp1[0].copy())
				fullcombotmp1.clear()
			watcherarray.append(watcherarraytmp.copy())
			watcherarraytmp.clear()
			fullcombo.append(fullcombotmp2.copy())
			fullcombotmp2.clear()
#full1stlayercombo = c_pool+fullcombo
#full1stlayeroutput = poolarray+watcherarray
full1stlayercombo = fullcombo
full1stlayeroutput = watcherarray
for i in range(0,len(full1stlayercombo)):
	print(full1stlayercombo[i])
	print(full1stlayeroutput[i])
#=========================================second layer: tensor for each pool element=========================================
poolnode = []
for ipool in range(0,pool):
	firstiter0 = 1
	for icombo in range(0,len(full1stlayercombo)):
		firstiter = 1
		for iincombo in range(0,len(full1stlayercombo[icombo])):
			if ipool in full1stlayercombo[icombo][iincombo]:
				ncb = 1
				if firstiter == 1:
					poolnodeadd = full1stlayeroutput[icombo][iincombo]
					firstiter = 0
				else :
					poolnodeadd = Add()([poolnodeadd,full1stlayeroutput[icombo][iincombo]])
					ncb += 1
		if firstiter0 == 1:
			poolconc = poolnodeadd
			firstiter0 = 0;
		else:
			poolconc = Concatenate(1)([poolconc,poolnodeadd])
	poolnode.append(poolconc)
	print(poolconc)
#=========================================third layer: output=========================================
outputlayeralgo1 = Dense(4*pool, activation='sigmoid')
outputlayeralgo = Dense(outputcategory, activation='softmax')
#outputlayeralgo = Dense(3, activation='softmax')
outputlayernode = []
for tensor in poolnode:
	outputlayernode.append(outputlayeralgo(tensor))
model = Model(inputs=inputs, outputs=outputlayernode)
#sgd = optimizers.SGD(lr=1, decay=1e-6, momentum=0.9, nesterov=True)
#model.compile(loss='mean_squared_error', optimizer="sgd")
model.compile(loss='categorical_crossentropy', optimizer="sgd")

#=========================================training data=========================================

rawdatatrain = readfiles(config['DEFAULT']['traindata'])
rawdatatest = readfiles(config['DEFAULT']['testdata'])
datatrain = [rawdatatrain[x] for x in range(0,len(rawdatatrain)) if (x+1)%(nobj+1) > 0]
datatest = [rawdatatest[x] for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) > 0]
rawdata = datatrain + datatest

pt = [x[0] for x in rawdata]
eta = [x[1] for x in rawdata]
phi = [x[2] for x in rawdata]
e  = [x[3] for x in rawdata]
ptmean = mean(pt )
etamean = mean(eta)
phimean = mean(phi)
emean = mean(e  )
ptstddev = stddev(pt )
etastddev = stddev(eta)
phistddev = stddev(phi)
estddev = stddev(e)

trainweight = [rawdatatrain[x][0] for x in range(0,len(rawdatatrain)) if (x+1)%(nobj+1) == 0]
trainweightlib = {i: trainweight[i] for i in range(0, len(trainweight))}

traindatastd = [[(x[0]-ptmean)/ptstddev,(x[1]-etamean)/etastddev,(x[2]-phimean)/phistddev,(x[3]-emean)/estddev] for x in datatrain]
traininput = list(np.array([np.array(traindatastd[x:x+nobj]) for x in range(0, len(traindatastd), nobj)]).transpose((1,0,2)))
trainoutput = [[x[4],x[5]+x[6]] if len(x)==7 else [0,0] for x in datatrain]
trainoutput = list(np.array([np.array(trainoutput[x:x+pool]) for x in range(0, len(trainoutput), nobj)]).transpose((1,0,2)))

testweight = [rawdatatest[x][0] for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) == 0]
testweightlib = {i: testweight[i] for i in range(0, len(testweight))}
testdatastd = [[(x[0]-ptmean)/ptstddev,(x[1]-etamean)/etastddev,(x[2]-phimean)/phistddev,(x[3]-emean)/estddev] for x in datatest]
testinput = list(np.array([np.array(testdatastd[x:x+nobj]) for x in range(0, len(testdatastd), nobj)]).transpose((1,0,2)))
testoutput = [[x[4],x[5]+x[6]] if len(x)==7 else [0,0] for x in datatest]
testoutput = list(np.array([np.array(testoutput[x:x+pool]) for x in range(0, len(testoutput), nobj)]).transpose((1,0,2)))

history = model.fit(traininput,trainoutput,class_weight=trainweightlib, validation_data = (testinput,testoutput,testweightlib), epochs=5000, batch_size = 64,
			callbacks=[EarlyStopping(monitor='val_loss', min_delta=0.0001, patience=10, verbose=0, mode='auto', baseline=None)])

#=========================================save model=========================================
model.save(modelname+'.h5', include_optimizer=False)
convert_model.convert(modelname+'.h5',modelname+'.json')

print("stddev: ", ptstddev,etastddev,phistddev,estddev)
print("mean: ", ptmean,etamean,phimean,emean)

#=========================================plot history for loss=========================================
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.savefig(modelname+'.eps')
#plt.show()

