
#trex-fitter h config/allsig/3l.config
#trex-fitter h config/allsig/ss2l.config

signals=("GHH300X" "GHH300Y" "GHH3f600f0" "GHH3fm600f0" "GHH3f350f2100" "GHH3fm350f2100" "GHH3fm350fm2100" "GHH3f350fm2100" "GHH3f0f3000" "GHH3f0fm3000" "GHH600X" "GHH600Y" "GHH6f650f0" "GHH6fm650f0" "GHH6f400f2400" "GHH6fm400f2400" "GHH6fm400fm2400" "GHH6f400fm2400" "GHH6f0f3500" "GHH6f0fm3500" "GHH900X" "GHH9f800f0" "GHH9fm800f0" "GHH9f600f3600" "GHH9fm600f3600" "GHH9fm600fm3600" "GHH9f600fm3600" "GHH9f0f5000" "GHH9f0fm5000")

runfit(){
	sig=$1
	mkdir -p $sig/Fit3l_Reg3lMhh
	mkdir -p $sig/Fitss2l_Meff
	mkdir -p $sig/combined
	trex-fitter w config/allsig/3l.config "Signal=$sig"
	trex-fitter w config/allsig/ss2l.config "Signal=$sig"
	trex-fitter mw combine.config "Signal=$sig"
	trex-fitter mf combine.config "Signal=$sig"
	trex-fitter ml combine.config "Signal=$sig"
	rm -rf $sig/Fit3l_Reg3lMhh/RooStats
	\mv Fit3l_Reg3lMhh/RooStats $sig/Fit3l_Reg3lMhh/.
	rm -rf $sig/Fitss2l_Meff/RooStats
	\mv Fitss2l_Meff/RooStats $sig/Fitss2l_Meff/.
	rm -rf $sig/combined
	\mv combined $sig/.
	trex-fitter f config/allsig/3l.config "Signal=$sig:Job=$sig/Fit3l_Reg3lMhh"
	trex-fitter l config/allsig/3l.config "Signal=$sig:Job=$sig/Fit3l_Reg3lMhh"
	trex-fitter f config/allsig/ss2l.config "Signal=$sig:Job=$sig/Fitss2l_Meff"
	trex-fitter l config/allsig/ss2l.config "Signal=$sig:Job=$sig/Fitss2l_Meff"
}
run3lfit(){
	sig=$1
	mkdir -p $sig/Fit3l_Reg3lMhh
	trex-fitter w config/allsig/3l.config "Signal=$sig"
	rm -rf $sig/Fit3l_Reg3lMhh/RooStats
	\mv Fit3l_Reg3lMhh/RooStats $sig/Fit3l_Reg3lMhh/.
	trex-fitter f config/allsig/3l.config "Signal=$sig:Job=$sig/Fit3l_Reg3lMhh"
        trex-fitter l config/allsig/3l.config "Signal=$sig:Job=$sig/Fit3l_Reg3lMhh"
}
if (( $# >= 1 )) ; then
	#runfit $1
	run3lfit $1
else
for sig in "${signals[@]}"
do
	runfit $sig
done
fi
