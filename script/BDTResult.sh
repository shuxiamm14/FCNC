#!/bin/bash

for files in `ls OptimResult_*`
do
	channel=${files/OptimResult_/}
	channel=${channel/.txt/}
	echo $channel `cat $files` >> tmpOptimResult
	#trainBDT_run $channel 2 `cat $files`
done
print_BDT_optim_run tmpOptimResult
