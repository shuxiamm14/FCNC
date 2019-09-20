
if test $# -lt 1; then
  echo "Something wrong with your input arguments, please re-run it."
  echo "Usage: ./hadhadpreparejobs.sh /absolute/path/of/datasets"

else
	for samplefiles in `ls $ttH_fakes_DIR/datafiles/xTFW/ | grep txt`
	do
		AODnumber=0
		DAODnumber=0
		for dsid in `cat $ttH_fakes_DIR/datafiles/xTFW/$samplefiles`
		do
			for DAODs in `grep $dsid /eos/user/b/boyang/SyncMyPC/jobManagement/datasets/r21_fcnc_DS/mc16.txt`
			do
				DAODninfile=`rucio list-files $DAODs | grep "Total events" | awk -F ' ' '{print $3}'`
				$((DAODnumber+=DAODninfile))
				AODninfile=`rucio list-files ${DAODs s/deriv.DAOD_HIGG4D3/recon.AOD/} | grep "Total events" | awk -F ' ' '{print $3}'`
				$((AODnumber+=AODninfile))
			done
		done
		echo $AODnumber $DAODnumber
	done
fi
