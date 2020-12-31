signal=(fcnc_prod_uh fcnc_prod_ch fcnc_ch fcnc_uh tuH tcH)
region=(reg1l1tau1b1j_ss reg1l1tau1b2j_ss reg1l1tau1b2j_os reg1l1tau1b3j_os reg1l2tau1bnj_os)



for sig in ${signal[@]}
do
	#echo "epstopdf $sig/combined_BDT_test/Limits.eps $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf"
	#epstopdf $sig/combined_BDTG_test/Limits.eps $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf
	for reg in ${region[@]}
	do
		echo "epstopdf $sig/combined_BDTG_test/Plots/$reg.eps $FCNC_DIR/FCNCFigures/tthML/Limit/$reg.pdf"
		epstopdf $sig/combined_BDTG_test/Plots/$reg.eps $FCNC_DIR/FCNCFigures/tthML/Limit/$reg.pdf
		echo "epstopdf $sig/combined_BDTG_test/Plots/${reg}_postFit.eps $FCNC_DIR/FCNCFigures/tthML/Limit/${reg}_postFit.pdf"
		epstopdf $sig/combined_BDTG_test/Plots/${reg}_postFit.eps $FCNC_DIR/FCNCFigures/tthML/Limit/${reg}_postFit.pdf
	done
done

epstopdf tuH/combined_BDTG_test/RankingSysts_SigXsecOverSM.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tuH_Ranking.pdf
epstopdf tcH/combined_BDTG_test/RankingSysts_SigXsecOverSM.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tcH_Ranking.pdf
epstopdf tuH/combined_BDTG_test/NuisPar.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tuH_NuisPar.pdf
epstopdf tcH/combined_BDTG_test/NuisPar.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tcH_NuisPar.pdf
epstopdf tuH/combined_BDTG_test/CorrMatrix.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tuH_CorrMatrix.pdf
epstopdf tcH/combined_BDTG_test/CorrMatrix.eps $FCNC_DIR/FCNCFigures/tthML/Limit/tcH_CorrMatrix.pdf