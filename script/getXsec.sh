if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./getXsec.sh datasets"
else
rm Xsecs.txt
	for lines in `cat $1`
	do 
		if [[ $lines =~ ":" ]]; then
			lines=`echo $lines | awk -F ':' '{print $2}'`
		fi
		echo -n `echo -n $lines | awk -F '.' '{print $2}'` >> Xsecs.txt
		for digits in `ami show dataset info $lines | egrep "crossSection_mean|genFiltEff |kFactor" | awk -F ': ' '{print $2}'`
		do
			echo -n " "$digits >> Xsecs.txt
		done
		if [ "`ami show dataset info $lines | egrep 'kFactor'`" == "" ]; then
			echo -n " 1" >> Xsecs.txt
		fi
		echo >> Xsecs.txt
	done
fi