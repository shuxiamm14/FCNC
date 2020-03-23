#!/bin/bash

touch $1_log
rm $1_log
for i in {0..170}
do
	if [[ $1 =~ "fit" ]] && [ $i -ge 160 ] && [ $i -le 166 ] ; then
		continue
	fi
	make_plots_run tthML $i $i $1 >> $1_log
done
