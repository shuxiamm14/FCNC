source env.sh

if [ -z ${PLOT_LIB_DIR+x} ] ; then
	echo 'please install plotTools https://gitlab.cern.ch/boyang/plotTools as README instructed'
	echo 'Then do `source plotTools/env.sh`'
	echo 'After this you can `source setup.sh` again'
	return
fi

if [ -z ${TOOL_DIR} ] ; then
	echo 'please put the external tools as listed in the README into a directory'
	echo 'Then do `export TOOL_DIR=/your/directory`'
	echo 'After this you can `source setup.sh` again'
	return
fi


LAUNCHER="-DCMAKE_CXX_COMPILER_LAUNCHER=distcc"
command -v distcc >/dev/null 2>&1 || { 
	echo >&2 "distcc is not installed, distributed compilation is disabled.";
	LAUNCHER=
}

for word in `root-config --cflags`
do
	if [[ "$word" =~ "-std=" ]] ; then
		CXX_STANDARD=`echo $word | tr -dc '0-9'`
		if ((CXX_STANDARD<5)) ; then
			if ((CXX_STANDARD==0)) ; then
				CXX_STANDARD=11;
			elif [[ "$word" =~ "1y" ]] ; then
				CXX_STANDARD=14;
			elif [[ "$word" =~ "1z" ]]; then
				CXX_STANDARD=17;
			else
				echo "ERROR: CXX_STANDARD not found"
				return
			fi
		fi
		break;
	fi
done

echo "-- Detected root CXX standard:" $CXX_STANDARD
if ((CXX_STANDARD==11)) ; then
	echo "-- Detected CXX standard less than 14 is not supported. Using CXX 14."
	CXX_STANDARD=14
fi
mkdir -p build ; cd build ; cmake .. -DCMAKE_CXX_STANDARD=$CXX_STANDARD $LAUNCHER; make -j4 install ; cd ..