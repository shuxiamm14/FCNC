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

mkdir build ; cd build ; cmake .. ; make install ; cd ..