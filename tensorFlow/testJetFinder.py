#!/usr/local/bin/python3
# create_model.py
import numpy as np

import configparser
import tensorflow as tf
import sys
from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.layers import Add, Concatenate, Lambda
from tensorflow.keras.models import Model, load_model
from tensorflow.keras.backend import int_shape
from itertools import permutations
from itertools import combinations
from tensorflow.keras.utils import plot_model
from tensorflow.keras.callbacks import ReduceLROnPlateau

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

nobj = 0
for x in watchers:
	nobj+=x
nwatcies = nobj
nobj+=pool


model = load_model(modelname+'.h5')
model.compile(loss='mean_squared_error', optimizer="sgd")
rawdatatrain = readfiles(config['DEFAULT']['traindata'])
rawdatatest = readfiles(config['DEFAULT']['testdata'])
datatrain = [rawdatatrain[x] for x in range(0,len(rawdatatrain)) if (x+1)%(nobj+1) > 0]
datatest = [rawdatatest[x] for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) > 0]
rawdata = datatrain + datatest

inputdata = []
datamean = []
datastddev = []
for idim in range(0,unitDim):
	inputdata.append([x[idim+1] for x in rawdata])
	datamean.append(mean(inputdata[idim]))
	datastddev.append(stddev(inputdata[idim]))

trainweight = [rawdatatrain[x][0] for x in range(0,len(rawdatatrain)) if (x+1)%(nobj+1) == 0]
trainweightlib = {i: trainweight[i] for i in range(0, len(trainweight))}

traindatastd = [[(x[idim+1]-datamean[idim])/datastddev[idim] for idim in range(0,unitDim)] for x in datatrain]
traininput = list(np.array([np.array(traindatastd[x:x+nobj]) for x in range(0, len(traindatastd), nobj)]).transpose((1,0,2)))
trainoutput = [[x[4],x[5]+x[6]] if len(x)==7 else [0,0] for x in datatrain]
trainoutput = list(np.array([np.array(trainoutput[x:x+pool]) for x in range(0, len(trainoutput), nobj)]).transpose((1,0,2)))

testweight = [rawdatatest[x][0] for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) == 0]
testweightlib = {i: testweight[i] for i in range(0, len(testweight))}
testdatastd = [[(x[idim+1]-datamean[idim])/datastddev[idim] for idim in range(0,unitDim)] for x in datatest]
testinput = list(np.array([np.array(testdatastd[x:x+nobj]) for x in range(0, len(testdatastd), nobj)]).transpose((1,0,2)))
testoutput = [[x[4],x[5]+x[6]] if len(x)==7 else [0,0] for x in datatest]
testoutput = list(np.array([np.array(testoutput[x:x+pool]) for x in range(0, len(testoutput), nobj)]).transpose((1,0,2)))
invmassrec = [int(rawdatatest[x][1]) for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) == 0]

predicted = np.array(model.predict(testinput)).transpose((1,0,2))
truth = np.array(testoutput).transpose((1,0,2))
matchedtot = 0;
invmassmatchedtot = 0;
tot = 0;
for i in range(0,len(truth)):
	fcncjet = -1
	matched = 1
	if invmassrec[i]>=len(truth[i]):
		continue
	for j in range(0,len(truth[i])):
		print(truth[i][j],predicted[i][j])
		if truth[i][j][0] == 1 :
			fcncjet = j
	for j in range(0,len(truth[i])):
		if fcncjet != j and predicted[i][j][0] >= predicted[i][fcncjet][0]:
			matched = 0
	tot += testweight[i]
	if matched:
		matchedtot += testweight[i]
	if fcncjet==invmassrec[i]:
		invmassmatchedtot += testweight[i]
	print(matched,fcncjet==invmassrec[i],invmassrec[i])
print("matching rate ML: ", float(matchedtot)/tot)
print("matching rate kine: ", float(invmassmatchedtot)/tot)
print("mean:",datamean)
print("stdd:",datastddev)
