ls $ttH_fakes_DIR/datafiles/xTFW/ | grep txt > tmp.txt

xtfw_print_cutflow_run tmp.txt | grep -v Developed | grep -v Copyright | grep -v please> cutflow

column -t -s $'\t' cutflow

rm cutflow tmp.txt