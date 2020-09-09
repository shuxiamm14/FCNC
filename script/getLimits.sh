variable=BDTG_test
signals=("tcH" "tuH" "fcnc_ch" "fcnc_uh" "fcnc_prod_ch" "fcnc_prod_uh")
regions=("reg1l1tau1b2j_os" "reg1l1tau1b3j_os" "reg1l2tau1bnj_os")
runfit(){
	sig=$1
	for reg in ${regions[@]}
	do
		mkdir -p $sig/${reg}_$variable
	done
	mkdir -p $sig/combined
	for reg in ${regions[@]}
	do
		trex-fitter w config/$reg/$variable.config "Signal=$sig"
	done
	trex-fitter mw combine.config "Signal=$sig"
	trex-fitter mf combine.config "Signal=$sig"
	trex-fitter ml combine.config "Signal=$sig"
	for reg in ${regions[@]}
	do
		rm -rf $sig/${reg}_$variable/RooStats
		mv ${reg}_$variable/RooStats $sig/${reg}_$variable/.
	done
	rm -rf $sig/combined
	mv combined $sig/.
	for reg in ${regions[@]}
	do
		trex-fitter f config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
		trex-fitter l config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
	done
}

runfitcomb(){
	sig=$1
	for reg in ${regions[@]} "combined"
	do
		mkdir -p $sig/${reg}_$variable
		trex-fitter w config/$reg/$variable.config "Signal=$sig"
		rm -rf $sig/${reg}_$variable/RooStats
		mv ${reg}_$variable/RooStats $sig/${reg}_$variable/.
		trex-fitter f config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
		trex-fitter l config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
	done
}

if (( $# >= 1 )) ; then
	for reg in ${regions[@]} "combined"
	do
		trex-fitter h config/$reg/$variable.config
	done
	runfitcomb $1
else
	for reg in ${regions[@]} "combined"
	do
		trex-fitter h config/$reg/$variable.config
	done
	for sig in "${signals[@]}"
	do
		runfitcomb $sig
	done
fi
