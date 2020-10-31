signal=(fcnc_prod_uh fcnc_prod_ch fcnc_ch fcnc_uh tuH tcH)
region=(reg1l1tau1b2j_os_BDTG_test reg1l1tau1b3j_os_BDTG_test reg1l2tau1bnj_os_BDTG_test combined)



for sig in ${signal[@]}
do
	echo "epstopdf $sig/combined/Limits.eps $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf"
	epstopdf $sig/combined/Limits.eps $FCNC_DIR/FCNCFigures/tthML/Limit/StatOnly/$sig.pdf
done