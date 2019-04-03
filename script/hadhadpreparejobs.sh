
if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./hadhadpreparejobs.sh /absolute/path/of/datasets"

else
mkdir -p $ttH_fakes_DIR/datafiles/xTFW/run
rm $ttH_fakes_DIR/datafiles/xTFW/run/mc16*
for samplefiles in `find "$ttH_fakes_DIR/datafiles/xTFW/" -name *.txt`
do
	for lines in `cat $samplefiles`
	do
		for files in `find $1/mc/*$lines*r9364*/*`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'` 
		done
		for files in `find $1/mc/*$lines*r10201*/*`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
		done
		for files in `find $1/mc/*$lines*r10724*/*`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
		done
	done
done
for files in `find $1/data/*/*`
do
	echo $files >> $ttH_fakes_DIR/datafiles/xTFW/run/data.txt
done
fi
