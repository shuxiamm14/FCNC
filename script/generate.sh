
signals=("GHH300Y" "GHH3f600f0" "GHH3fm600f0" "GHH3f350f2100" "GHH3fm350f2100" "GHH3fm350fm2100" "GHH3f350fm2100" "GHH3f0f3000" "GHH3f0fm3000" "GHH600X" "GHH600Y" "GHH6f650f0" "GHH6fm650f0" "GHH6f400f2400" "GHH6fm400f2400" "GHH6fm400fm2400" "GHH6f400fm2400" "GHH6f0f3500" "GHH6f0fm3500" "GHH900X" "GHH9f800f0" "GHH9fm800f0" "GHH9f600f3600" "GHH9fm600f3600" "GHH9fm600fm3600" "GHH9f600fm3600" "GHH9f0f5000" "GHH9f0fm5000")
echo $signals
for sig in "${signals[@]}"
do
	echo "ReplacementFile:myFit.config
XXXjobname:Meff2l
XXXvariable:Meff2l
XXXxaxis:M_{eff}^{2l}[GeV]
XXXsig:$sig
XXXsrvt:\"VH#rightarrow VVV\"
XXXlog:FALSE" > config/$sig
done


