
if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./hadhadpreparejobs.sh /datasets/path sample.txt"

else

for lines in $2
	for files in `find $1/*$lines*r9364*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/mc16a_$2
	done
	for files in `find $1/*$lines*r10201*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/mc16d_$2
	done
	for files in `find $1/*$lines*r10724*/*`
	do
		echo -n $lines" "$files >> ../../datafiles/xTFW/mc16e_$2
	done
done