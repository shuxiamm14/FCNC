#!/bin/bash


#usage: addhists.sh <framework, tthML/xTFW>
framework=$1
NOMINAL=NOMINAL

if [[ $framework == "tthML" ]]; then
	NOMINAL=nominal
fi
for weightsys in `cat $ttH_fakes_DIR/config/theoryweightlist/${framework}_410470.txt`
do
	hadd hist_$weightsys.root $NOMINAL/*_$weightsys.root
done

for treesys in `cat $ttH_fakes_DIR/config/${framework}treeSys.txt`
do
	hadd hist_$treesys.root $treesys/*fakeSF_tthML.root 
done