#!/bin/bash
command=print_importance_run
for (( i = 1; i < 3; i++ )); do
	ls Importance*_$i.txt > Importance_$i.tmp
	command="$command Importance_$i.tmp"
done
$command
for (( i = 1; i < 3; i++ )); do
	rm Importance_$i.tmp
done
