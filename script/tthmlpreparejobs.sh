
mkdir -p $ttH_fakes_DIR/datafiles/tthML/v2/run
rm $ttH_fakes_DIR/datafiles/tthML/v2/run/*
allsamplefile=$ttH_fakes_DIR/datafiles/tthML/v2/run/allsamples.txt
cat /global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV9/*.list | sort > $allsamplefile
RemoveReplicateLines $allsamplefile
sed -i "s#../..#/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop#" $allsamplefile
for samplefiles in `find "$ttH_fakes_DIR/datafiles/tthML/v2/" -name *.txt`
do
	for lines in `cat $samplefiles`
	do
		for files in `grep $lines $allsamplefile`
		do
			if [[ $files =~ "mc16a" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16d" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16e" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
		done
	done
done
for files in `grep data $allsamplefile`
do
	if [[ $files =~ "data15" ]] || [[ $files =~ "data16" ]] ; then
		echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data1516.txt
	fi
	if [[ $files =~ "data17" ]] ; then
		echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data17.txt
	fi
	if [[ $files =~ "data18" ]] ; then
		echo $files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/data18.txt
	fi
done

