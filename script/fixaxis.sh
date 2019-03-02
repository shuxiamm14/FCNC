for lines in `ls *.json`
do
	sed -i "backup" "s/\"axis\": 1/\"axis\": 3/g" $lines
done
rm *backup