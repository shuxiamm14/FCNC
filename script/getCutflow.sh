#skim = Tau nTracks cut, Tau ID cut (2 loose), njet >= 3, nbjet >= 1, Di-tau trigger & trigger matching

#ls $ttH_fakes_DIR/datafiles/xTFW/ | grep txt > tmp.txt
#echo Raw cutflow > cutflow
#xtfw_print_cutflow_run tmp.txt cutflow_HSM_common_raw | grep -v Developed | grep -v Copyright | grep -v please >> cutflow
#echo Weighted cutflow >> cutflow
#xtfw_print_cutflow_run tmp.txt cutflow_HSM_common_weighted | grep -v Developed | grep -v Copyright | grep -v please >> cutflow

#column -t -s $'\t' cutflow

for lines in `cat $ttH_fakes_DIR/config/reduce/config.defalt | grep mc16a | awk -F ' ' '{print $2}'`
do
	echo ${lines//_mc16a/}
done

#rm cutflow tmp.txt