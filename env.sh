#!/bin/bash
if [ -z ${ttH_fakes_DIR+x} ] ; then
	SOURCE="${BASH_SOURCE[0]}"
	while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
	  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
	  SOURCE="$(readlink "$SOURCE")"
	  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
	done
	export ttH_fakes_DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
	export PATH+=:$ttH_fakes_DIR/bin:$ttH_fakes_DIR/script:$ttH_fakes_DIR/tensorflow:$ttH_fakes_DIR/scripts
	if [ $(uname) = "Darwin" ]; then
		export DYLD_LIBRARY_PATH+=:$ttH_fakes_DIR/lib
	else
		export LD_LIBRARY_PATH+=:$ttH_fakes_DIR/bin
	fi
	alias tth='cd $ttH_fakes_DIR'
	alias tthmake='cd $ttH_fakes_DIR/build; make; cd -'
fi

Order(){
  infile=$1
  cat ${infile} | sort -n > "${infile}_sorted"
  \rm ${infile}
  mv "${infile}_sorted" $1
}


RemoveReplicateLines()
{
prlines=""
Order $1
cat $1 | while read lines
do
        if [[ $lines == $prlines ]]; then
                continue
        fi
        prlines=$lines
        echo $lines >> $1_tmp
done
\mv $1_tmp $1
}
