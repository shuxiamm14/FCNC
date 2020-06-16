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
if [ -n "$3" ] && [[ $3 != "all" ]] ; then
	systname=$3
fi

test=`echo $systname | awk -F " " '{print $1}'| grep "#"`
if [ "$test" != "" ]; then
	continue;
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

rm -f sublocal.sh

#for i in {1..4}
#do
#	if [[ $1 =~ $i ]] ; then
#		echo "reduce_run tthML $i"' $1'" $systname"  >> bulkreduce.sh
#		echo "reduce_run tthML $i"' $1'" $systname"  >> sublocal.sh
#	fi
#done

if [[ $2 =~ "sub" ]] ; then
	for lines in `ls $ttH_fakes_DIR/datafiles/tthML/v3/run/{mc*,data*}  | xargs -n 1 basename`
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
		if [ -n "$4" ] && [[ $4 != $lines ]] ; then
			continue
		fi
		rm -f $name.out
		rm -f ${name}_evt.txt
		for i in `echo $1| sed -e 's/\(.\)/\1\n/g'`
		do
			echo "reduce_run tthML $i $lines $systname >> $name$i.out"  >> bulkreduce.sh
			echo "reduce_run tthML $i $lines $systname >> $name$i.out"  >> sublocal.sh
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
if [[ $2 =~ "sub" ]] ; then
if [[ $2 =~ "local" ]] ; then
	./sublocal.sh 2>&1 &
else
	if [ -n "$4" ] ; then
		sbatch --job-name=${systname}_$4 --output=$4.out  --error=$4.err slurmscript.sh
	else
		sbatch --job-name=${systname} --output=job.out --error=job.err slurmscript.sh
		#echo "sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines"
		#sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines
	fi
fi
fi

cd ..
if [ -n "$3" ] && [[ $3 != "all" ]] ; then
	break
fi
done
