
rundir=$ttH_fakes_DIR/datafiles/tthML/v2

for sysfiles in `ls $rundir/run/sys_*.txt`
do
	echo $sysfiles
	nomfile=${sysfiles/sys_/}
	cat $sysfiles | awk '{print $1}' > tmp
	cat $nomfile | awk '{print $1}' > tmp1
	Order tmp1
	Order tmp
	RemoveReplicateLines tmp
	RemoveReplicateLines tmp1
	diff tmp tmp1
done
rm tmp tmp1
