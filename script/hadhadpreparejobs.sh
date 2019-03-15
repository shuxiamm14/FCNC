
if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./hadhadpreparejobs.sh /datasets/path sample.txt"

else
mkdir -p ../../datafiles/xTFW/run
for samplefiles in `find ../../datafiles/xTFW/*.txt`
do
for lines in `cat samplefiles`
	for files in `find $1/*$lines*r9364*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/run/mc16a_$2
	done
	for files in `find $1/*$lines*r10201*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/run/mc16d_$2
	done
	for files in `find $1/*$lines*r10724*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/run/mc16e_$2
	done
done