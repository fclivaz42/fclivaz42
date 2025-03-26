#!/bin/bash

LOCKFILE="$XDG_RUNTIME_DIR/volcheck.lock"
CHCKFILE="$XDG_RUNTIME_DIR/volcheck"

popup()
{
	touch $LOCKFILE
	eww open volpopup &>/dev/null
	while [ $(expr `date +%s` - `date -r $CHCKFILE +%s`) -lt 2 ]; do
		sleep 1
	done
	eww close volpopup &>/dev/null
	rm $LOCKFILE
}

while true; do
	echo "$(cat $XDG_RUNTIME_DIR/volume)" | tee $CHCKFILE
	[ ! -f "$LOCKFILE" ] && popup &
done
