#!/bin/bash

for files in `ls $ttH_fakes_DIR/datafiles/tthML/v4/*.txt`
do
	filename=`echo $files | awk -F "/" '{print $NF}'`
	DSname=`echo ${filename/.txt}`
	echo ${DSname//_/ }
	DSs=`cat $files`
	echo
	echo $DSs
	echo
done