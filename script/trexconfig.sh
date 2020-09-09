regions=("reg1l1tau1b3j_os" "reg1l1tau1b2j_os" "reg1l2tau1bnj_os" "combined")
regiontitle=("TTH #it{#tau_{lep}#tau_{had}}" "STH #it{#tau_{lep}#tau_{had}}" "#it{l#tau_{had}#tau_{had}}" "Combined")
variable="BDTG_test"
variabletitle="BDT Discriminant"
log="FALSE"
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
XXXregion:\"reg1l1tau1b3j_os\";\"reg1l1tau1b2j_os\";\"reg1l2tau1bnj_os\"
XXXregopt:\"reg1l1tau1b3j_os\",\"reg1l1tau1b2j_os\",\"reg1l2tau1bnj_os\"
XXXlabel:\"leptonic Combined\"
XXXhistoPathSuff:\"/reg1l1tau1b3j_os\";\"/reg1l1tau1b2j_os\";\"/reg1l2tau1bnj_os\"" > config/combined/$variable.config
