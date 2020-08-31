mkdir -p $ttH_fakes_DIR/datafiles/xTFW/v3/run
rm $ttH_fakes_DIR/datafiles/xTFW/v3/run/*
for samplefiles in `find "$ttH_fakes_DIR/datafiles/xTFW/v3/bkg/" -name *.txt`
do
        for lines in `cat $samplefiles`
        do
                for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/mc/hadhad/mc16a/nom/*$lines*r9364*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
                for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/mc/hadhad/mc16d/nom/*$lines*r10201*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
                for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/mc/hadhad/mc16e/nom/*$lines*r10724*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
        done
done

for samplefiles in `find "$ttH_fakes_DIR/datafiles/xTFW/v3/sig/" -name *.txt`
do
        for lines in `cat $samplefiles`
        do
                for files in `find /afs/cern.ch/work/m/mxia/xTFW/hadhad_fcnc_signal/signal/*$lines*r9364*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16a_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
                for files in `find /afs/cern.ch/work/m/mxia/xTFW/hadhad_fcnc_signal/signal/*$lines*r10201*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16d_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
                for files in `find /afs/cern.ch/work/m/mxia/xTFW/hadhad_fcnc_signal/signal/*$lines*r10724*/*`
                do
                        echo $lines" "$files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/mc16e_`echo $samplefiles | awk -F "/" '{print $NF}'`
                done
        done
done



for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/data/hadhad/data15/*data15*/*`
do
        echo $files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/data1516.txt
done

for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/data/hadhad/data16/*data16*/*`
do
        echo $files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/data1516.txt
done
for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/data/hadhad/data17/*data17*/*`
do
        echo $files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/data17.txt
done

for files in `find /eos/atlas/atlascerngroupdisk/phys-higgs/HSG4/SM_Htautau_R21/V03/data/hadhad/data18/*data18*/*`
do
        echo $files >> $ttH_fakes_DIR/datafiles/xTFW/v3/run/data18.txt
done
