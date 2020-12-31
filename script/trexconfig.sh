regions=("reg1l1tau1b1j_ss_highmet" "reg1l1tau1b2j_ss_highmet" "reg1l1tau1b3j_os_highmet" "reg1l1tau1b2j_os_highmet" "reg1l2tau1bnj_os" "combined")
regiontitle=("l#tau_{had}1j" "l#tau_{had}2j" "TTH #it{#tau_{lep}#tau_{had}}" "STH #it{#tau_{lep}#tau_{had}}" "#it{l#tau_{had}#tau_{had}}" "Combined")
variable="BDTG_test"
variabletitle="BDT Discriminant"
log="FALSE"

cp $ttH_fakes_DIR/config/trexfitter/tthML/myFit.config .
cp $ttH_fakes_DIR/config/trexfitter/tthML/combine.config .
cat $ttH_fakes_DIR/config/trexfitter/tthML/fake_sys.config >> myFit.config
#cat $ttH_fakes_DIR/config/trexfitter/tthML/Instrumental_sys.config >> myFit.config
if [[ $variable =~ 'BDTG' ]] ; then
	bin="Binning: -1,-0.4,0.1,0.3,0.5,0.65,0.75,0.85,1"
	log="TRUE"
fi
rebin=1
mkdir -p config
for i in {0..2}
do
	mkdir -p config/${regions[i]}
	echo "ReplacementFile:myFit.config
XXXjobname:${regions[i]}_$variable
XXXvariable:$variable
XXXxaxis:$variabletitle
XXXlog:$log
XXXrebin:$rebin
XXXBinning:$bin
XXXregion:${regions[i]}
XXXregopt:${regions[i]}
XXXlabel:\"${regiontitle[i]}\"
XXXhistoPathSuff:\"/${regions[i]}\";" > config/${regions[i]}/$variable.config
done

	mkdir -p config/combined
	echo "ReplacementFile:myFit.config
XXXjobname:combined_$variable
XXXvariable:$variable
XXXxaxis:$variabletitle
XXXlog:$log
XXXrebin:$rebin
XXXBinning:$bin
XXXregion:\"reg1l1tau1b3j_os\";\"reg1l1tau1b2j_os\";\"reg1l2tau1bnj_os\";\"reg1l1tau1b2j_ss\";\"reg1l1tau1b1j_ss\"
XXXregopt:\"reg1l1tau1b3j_os\",\"reg1l1tau1b2j_os\",\"reg1l2tau1bnj_os\",\"reg1l1tau1b2j_ss\",\"reg1l1tau1b1j_ss\"
XXXlabel:\"TTH #it{#tau_{lep}#tau_{had}}\";\"STH #it{#tau_{lep}#tau_{had}}\";\"#it{l#tau_{had}#tau_{had}}\";\"l#tau_{had}1j\";\"l#tau_{had}2j\"
XXXhistoPathSuff:\"/reg1l1tau1b3j_os_vetobtagwp70_highmet\";\"/reg1l1tau1b2j_os_vetobtagwp70_highmet\";\"/reg1l2tau1bnj_os\";\"reg1l1tau1b2j_ss_vetobtagwp70_highmet\";\"reg1l1tau1b1j_ss_vetobtagwp70_highmet\"" > config/combined/$variable.config
