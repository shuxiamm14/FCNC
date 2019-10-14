
mkdir -p $ttH_fakes_DIR/datafiles/tthML/v2/run
rm $ttH_fakes_DIR/datafiles/tthML/v2/run/*
allsamplefile=$ttH_fakes_DIR/datafiles/tthML/v2/run/allsamples.dat
sysallsamplefile=$ttH_fakes_DIR/datafiles/tthML/v2/run/sys_allsamples.dat
for files in `ls /global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV9/*.list`
do
	cat $files | sort >> $allsamplefile
	echo >> $allsamplefile
done
for files in `ls /global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimSysV9/*.list`
do
	cat $files | sort >> $sysallsamplefile
	echo >> $sysallsamplefile
done

Order $allsamplefile
Order $sysallsamplefile
RemoveReplicateLines $allsamplefile
RemoveReplicateLines $sysallsamplefile
sed -i "s#../..#/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop#" $allsamplefile
sed -i "s#../..#/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop#" $sysallsamplefile
for samplefiles in `find "$ttH_fakes_DIR/datafiles/tthML/v2/" -name *.txt`
do
	for lines in `cat $samplefiles`
	do
		nfilea=0
		nfiled=0
		nfilee=0
		for files in `grep $lines $allsamplefile`
		do
			if [[ $files =~ "mc16a" ]] ; then
				if (( nfilea == 0 )) ; then
					tmp=${files/_part*/.root}
					echo $lines" "${tmp/MytthAnaSkim/MysumWeights} >> $ttH_fakes_DIR/datafiles/tthML/v2/run/weightsum_mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
				fi
				(( nfilea ++ ))
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16d" ]] ; then
				if (( nfiled == 0 )) ; then
					tmp=${files/_part*/.root}
					echo $lines" "${tmp/MytthAnaSkim/MysumWeights} >> $ttH_fakes_DIR/datafiles/tthML/v2/run/weightsum_mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
				fi
				(( nfiled ++ ))
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16e" ]] ; then
				if (( nfilee == 0 )) ; then
					tmp=${files/_part*/.root}
					echo $lines" "${tmp/MytthAnaSkim/MysumWeights} >> $ttH_fakes_DIR/datafiles/tthML/v2/run/weightsum_mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
				fi
				(( nfilee ++ ))
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
		done
		for files in `grep $lines $sysallsamplefile`
		do
			if [[ $files =~ "mc16a" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/sys_mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16d" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/sys_mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
			fi
			if [[ $files =~ "mc16e" ]] ; then
				echo $lines" "$files >> $ttH_fakes_DIR/datafiles/tthML/v2/run/sys_mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
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

