#!/bin/bash


mkdir checkdone
for systname in `cat $ttH_fakes_DIR/config/tthMLtreeSys.txt`
do
	if [ -n "$2" ]; then
		systname=$2
	fi
	test=`echo $systname | awk -F " " '{print $1}'| grep "#"`
	if [ "$test" != "" ]; then
		continue;
	fi
	keyword="_NOMINAL.root"
	if [[ $1 == "4" ]] || [[ $1 == "6" ]] ; then
		keyword="fake_NOMINAL.root"
	fi
	grep $keyword $systname/*.out | sort | awk -F "/" '{print $2}' | awk -F ":" '{print $1}' > checkdone/finished_$systname.txt
	sed -i "s|$1.out|.txt|" checkdone/finished_$systname.txt
	sed -i "s|out|txt|" checkdone/finished_$systname.txt
	if [ "$systname" == "nominal" ] ; then
		ls $ttH_fakes_DIR/datafiles/tthML/v3/run | grep -e "^mc16*" |sort > checkdone/all_$systname.txt
		ls $ttH_fakes_DIR/datafiles/tthML/v3/run | grep -e "^data*" |sort >> checkdone/all_$systname.txt
		Order checkdone/all_$systname.txt
	else
		ls $ttH_fakes_DIR/datafiles/tthML/v3/run | grep sys_mc|sort > checkdone/all_$systname.txt
	fi
	sed -i "s|sys_||" checkdone/all_$systname.txt
	check=`diff checkdone/finished_$systname.txt checkdone/all_$systname.txt | grep ">" | awk '{print $2}'`
	if [ -n "$check" ] ; then
		echo $systname
		#echo "submit_tth_reduce.sh 1234 sub $systname"
		#submit_tth_reduce.sh 1234 sub $systname
		for samp in $check
		do
			echo "submit_tth_reduce.sh $1 sublocal $systname $samp"
			submit_tth_reduce.sh $1 sublocal $systname $samp
		done
	fi
	if [ -n "$2" ]; then
		break
	fi
done

