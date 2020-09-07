
mkdir -p config
#mkdir -p config/Meff
#mkdir -p config/Reg3lMhh
mkdir -p config/allsig

GHHTrexConfigDir=$ttH_fakes_DIR/config/trexfitter/GHH/
signals=("GHH300X" "GHH300Y" "GHH3f600f0" "GHH3fm600f0" "GHH3f350f2100" "GHH3fm350f2100" "GHH3fm350fm2100" "GHH3f350fm2100" "GHH3f0f3000" "GHH3f0fm3000" "GHH600X" "GHH600Y" "GHH6f650f0" "GHH6fm650f0" "GHH6f400f2400" "GHH6fm400f2400" "GHH6fm400fm2400" "GHH6f400fm2400" "GHH6f0f3500" "GHH6f0fm3500" "GHH900X" "GHH9f800f0" "GHH9fm800f0" "GHH9f600f3600" "GHH9fm600f3600" "GHH9fm600fm3600" "GHH9f600fm3600" "GHH9f0f5000" "GHH9f0fm5000")
sigstring=${signals[@]}

cat $GHHTrexConfigDir/job_3l.config > myFit_3l_allsig.config
cat $GHHTrexConfigDir/job_ss2l.config > myFit_ss2l_allsig.config

echo "  Samples: "${sigstring// /,} | tee -a myFit_3l_allsig.config myFit_ss2l_allsig.config > /dev/null

cat $GHHTrexConfigDir/samples_3l.config >> myFit_3l_allsig.config
cat $GHHTrexConfigDir/samples_ss2l.config >> myFit_ss2l_allsig.config


for sig in "${signals[@]}"
do
#	echo "ReplacementFile:myFit_ss2l.config
#XXXjobname:Fitss2l_$sig
#XXXvariable:Fitss2l_$sig
#XXXxaxis:M_{eff}^{2l}[GeV]
#XXXsig:$sig
#XXXsrvt:\"VH\rightarrow VVV\"
#XXXlog:FALSE
#XXXrebin:1" > config/Meff/$sig
#
#
#
#	echo "ReplacementFile:myFit_3l.config
#XXXjobname:Fit3l_$sig
#XXXvariable:Fit3l_$sig
#XXXxaxis:M_{H}[GeV]
#XXXsig:$sig
#XXXsrvt:\"VH\rightarrow VVV\"
#XXXlog:FALSE
#XXXrebin:1" > config/Reg3lMhh/$sig

	echo "
Sample: \"$sig\"
  Type: SIGNAL
  Title: \"VH\rightarrow VVV\"
  LineColor: 1
  FillColor: 2
  UseMCstat: FALSE
  HistoFile: \"$sig\"
  HistoName: \"NOMINAL\"" | tee -a myFit_3l_allsig.config myFit_ss2l_allsig.config > /dev/null
done

cat $GHHTrexConfigDir/systematics.config | tee -a myFit_3l_allsig.config myFit_ss2l_allsig.config > /dev/null

echo 'MultiFit: "combined"
  Label: "combined"
  Combine: TRUE
  Compare: FALSE
  CmeLabel: "13 TeV"
  LumiLabel: "139 pb^{-1}"
  ComparePOI: FALSE
  ComparePulls: FALSE
  CompareLimits: FALSE
  POIName: "SigXsecOverSM"
  POIRange: -10:30
  DataName: "asimovData"
  CombineChByCh: TRUE

Fit: "Fitss2l"
  ConfigFile: config/allsig/ss2l.config
  Label: "SR"

Fit: "Fit3l"
  ConfigFile: config/allsig/3l.config
  Label: "SR"' > combine.config



echo "ReplacementFile:myFit_ss2l_allsig.config
XXXvariable:Meff
XXXxaxis:M_{eff}^{2l}[GeV]
XXXlog:FALSE
XXXrebin:1" > config/allsig/ss2l.config

echo "ReplacementFile:myFit_3l_allsig.config
XXXvariable:Reg3lMhh
XXXxaxis:M_{H}[GeV]
XXXlog:FALSE
XXXrebin:1" > config/allsig/3l.config


#cp $GHHTrexConfigDir/myFit_3l.config .
#cp $GHHTrexConfigDir/myFit_ss2l.config .





