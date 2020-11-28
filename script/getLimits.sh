variable=BDTG_test
signals=("tcH" "tuH" "fcnc_ch" "fcnc_uh" "fcnc_prod_ch" "fcnc_prod_uh")
regions=("reg1l1tau1b1j_ss" "reg1l1tau1b2j_ss" "reg1l1tau1b3j_os" "reg1l1tau1b2j_os" "reg1l2tau1bnj_os" "combined")
usecombJO=1
runfit(){
	sig=$1
	for reg in ${regions[@]}
	do
		mkdir -p $sig/${reg}_$variable
	done
	mkdir -p $sig/combined
	for reg in ${regions[@]}
	do
		trex-fitter wpfl config/$reg/$variable.config "Signal=$sig"
	done
	trex-fitter mwfl combine.config "Signal=$sig"
	for reg in ${regions[@]}
	do
		rm -rf $sig/${reg}_$variable/*
		mv -f ${reg}_$variable/!(Histograms) $sig/${reg}_$variable/.
	done
	rm -rf $sig/combined
	mv -f combined $sig/.
}

runfitcomb(){
	sig=$1
	for reg in ${regions[@]} "combined"
	do
		mkdir -p $sig/${reg}_$variable
		trex-fitter w config/$reg/$variable.config "Signal=$sig"
		rm -rf $sig/${reg}_$variable/RooStats
		mv -f ${reg}_$variable/RooStats $sig/${reg}_$variable/.
		trex-fitter f config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
		trex-fitter l config/$reg/$variable.config "Signal=$sig:Job=$sig/${reg}_$variable"
	done
}

if (( $# >= 1 )) ; then
	if ((usecombJO==1)) ; then
		for reg in ${regions[@]}
		do
			trex-fitter h config/$reg/$variable.config
		done
		runfit $1
	else
		for reg in ${regions[@]} "combined"
		do
			trex-fitter h config/$reg/$variable.config
		done
		runfitcomb $1
	fi
else
	if ((usecombJO==1)) ; then
		for reg in ${regions[@]}
		do
			trex-fitter h config/$reg/$variable.config
		done
		for sig in "${signals[@]}"
		do
			runfit $sig
		done
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
fi
