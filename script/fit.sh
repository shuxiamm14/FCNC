#!/bin/bash

touch $1_log
rm $1_log
for i in {0..161}
do
	make_plots_run tthML $i $i $1 >> $1_log
done
