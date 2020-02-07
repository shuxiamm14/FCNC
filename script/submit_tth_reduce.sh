#!/bin/bash

#usage: 
#for nominal submission
#submit_tth_reduce.sh <reduce scheme (1/2/3/12/23/123)> sub nominal
#for systematics submission
#submit_tth_reduce.sh <reduce scheme (1/2/3/12/23/123)> sub
#for test
#submit_tth_reduce.sh <reduce scheme (1/2/3/12/23/123)> subtest
#no submission
#submit_tth_reduce.sh <reduce scheme (1/2/3/12/23/123)> generate (nominal)

mkdir -p /tmp/boyang/boyang
for systname in `cat $ttH_fakes_DIR/config/tthMLtreeSys.txt`
do
if [ -n "$3" ] ; then
	systname=$3
fi
mkdir -p $systname
cd $systname
echo '#!/bin/bash
#SBATCH --account=atlas
#SBATCH --qos=shared
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --constraint=haswell
#SBATCH --time=24:00:00
#SBATCH --mem=4GB
#SBATCH --image=zlmarshall/atlas-grid-slc6:20190416 --export=NONE
shifter --module=cvmfs /bin/bash bulkreduce.sh $1
' > slurmscript.sh
chmod +x slurmscript.sh

echo 'date
shopt -s expand_aliases
source /global/project/projectdirs/atlas/scripts/setupATLAS.sh
setupATLAS
lsetup "root 6.14.04-x86_64-slc6-gcc62-opt"
cd '`pwd`"
ulimit -n 32000
. $ttH_fakes_DIR/env.sh" > bulkreduce.sh

rm sublocal.sh

#for i in {1..4}
#do
#	if [[ $1 =~ $i ]] ; then
#		echo "reduce_run tthML $i"' $1'" $systname"  >> bulkreduce.sh
#		echo "reduce_run tthML $i"' $1'" $systname"  >> sublocal.sh
#	fi
#done

if [[ $2 =~ "sub" ]] ; then
	for lines in `ls $ttH_fakes_DIR/datafiles/tthML/v2/run/{mc*,data*}  | xargs -n 1 basename`
	do
		if [[ $systname != "nominal" ]] && ( [[ $lines =~ "wjet" ]] || [[ $lines =~ "zll" ]] || [[ $lines =~ "ztautau" ]] ) ; then
			continue
		fi
		touch ../done.txt
		donefind=`grep $lines ../done.txt`
		if [[ $donefind == $lines ]] ; then
			continue
		fi
		if ( [[ $lines =~ "data" ]] && [[ $systname != "nominal" ]] ) || [[ $lines =~ "sys" ]] ; then
			continue
		fi
		name=${lines/.txt}
		touch $name.out
<<<<<<< HEAD
		if [ -n "$4" ] && [[ $4 != $lines ]] ; then
			continue
		fi
		rm $name.out
		rm ${name}_evt.txt
=======
		rm $name.out
>>>>>>> 331f940d486a08101f32c0cb14c56dfd81eedd02
		for i in {1..4}
		do
			if [[ $1 =~ $i ]] ; then
				echo "reduce_run tthML $i $lines $systname >> $name.out"  >> bulkreduce.sh
				echo "reduce_run tthML $i $lines $systname >> $name.out"  >> sublocal.sh
			fi
		done
		#if [[ $2 =~ "local" ]] ; then
		#	./sublocal.sh $lines > ${name}.out 2>&1 &
		#else
		#	sbatch --job-name=${systname} --output=job.out --error=job.err slurmscript.sh $lines
		#	echo "sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines"
		#	sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines
		#fi
		if [[  $2 =~ "test" ]] ; then
			break
		fi
	done	
fi

chmod +x sublocal.sh
echo "date"   >> bulkreduce.sh
chmod +x bulkreduce.sh

if [[ $2 =~ "local" ]] ; then
	./sublocal.sh 2>&1 &
else
	sbatch --job-name=${systname} --output=job.out --error=job.err slurmscript.sh
	#echo "sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines"
	#sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines
fi


cd ..
if [ -n "$3" ] ; then
	break
fi
done
