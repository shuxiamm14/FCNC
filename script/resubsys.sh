#!/bin/bash


mkdir checkdone
for systname in `cat $ttH_fakes_DIR/config/tthMLtreeSys.txt`
do
	test=`echo $systname | awk -F " " '{print $1}'| grep "#"`
	if [ "$test" != "" ]; then
		continue;
	fi
	grep "fcnc_NOMINAL.root" $systname/*out | sort | awk -F "/" '{print $2}' | awk -F ":" '{print $1}' > checkdone/finished_$systname.txt
	sed -i "s|out|txt|" checkdone/finished_$systname.txt
	ls $ttH_fakes_DIR/datafiles/tthML/v2/run | grep sys_mc|sort > checkdone/all_$systname.txt
	sed -i "s|sys_||" checkdone/all_$systname.txt
	check=`diff checkdone/finished_$systname.txt checkdone/all_$systname.txt | grep ">" | awk '{print $2}'`
	if [ -n "$check" ] ; then
		echo $systname
		#echo "submit_tth_reduce.sh 1234 sublocal $systname"
		#submit_tth_reduce.sh 1234 sublocal $systname
		for samp in $check
		do
			echo "submit_tth_reduce.sh 1234 sublocal $systname $samp"
			#submit_tth_reduce.sh 1234 sublocal $systname $samp
		done
	fi
done

