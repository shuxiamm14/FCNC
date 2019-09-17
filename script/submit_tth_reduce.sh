#!/bin/bash
mkdir -p /tmp/boyang/boyang
for systname in `cat $ttH_fakes_DIR/config/tthmlSys.txt`
do
if [[ $3 =~ "nominal" ]] ; then
	systname=nominal
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
#SBATCH --mem=2GB
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

for i in {1..3}
do
	if [[ $1 =~ $i ]] ; then
		echo "reduce_run tthML $i"' $1'" $systname"  >> bulkreduce.sh
	fi
done

echo "date"   >> bulkreduce.sh
chmod +x bulkreduce.sh

if [[ $2 =~ "sub" ]] ; then
	for lines in `ls $ttH_fakes_DIR/datafiles/tthML/v2/run/{mc*,data*}  | xargs -n 1 basename`
	do
		if ( [[ $lines =~ "data" ]] || [[ $lines =~ "sys" ]] ) && [[ $systname != "nominal" ]] ; then
			continue
		fi
		name=${lines/.txt}
		echo "sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines"
		sbatch --job-name=${name}_${systname} --output=${name}.out --error=${name}.err slurmscript.sh $lines
		if [[  $2 =~ "test" ]] ; then
			break
		fi
	done	
fi
cd ..
if [[ $3 =~ "nominal" ]] ; then
	break
fi
done
