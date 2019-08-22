
if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./hadhadpreparejobs.sh /absolute/path/of/datasets"

else
mkdir -p $ttH_fakes_DIR/datafiles/tthML/v2/run
rm $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16*
for samplefiles in `find "$ttH_fakes_DIR/datafiles/tthML/v2/" -name *.txt`
do
	for lines in `cat $samplefiles`
	do
		for files in `find $1/*$lines*mc16a*.root`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'` 
		done
		for files in `find $1/*$lines*mc16d*.root`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
		done
		for files in `find $1/*$lines*mc16e*.root`
		do
			echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
		done
	done
done
for files in `find $1/*data15*.root`
do
	echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data1516.txt
done

for files in `find $1/*data16*.root`
do
	echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data1516.txt
done
for files in `find $1/*data17*.root`
do
	echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data17.txt
done

for files in `find $1/*data18*.root`
do
	echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data18.txt
done
fi
