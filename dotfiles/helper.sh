#!/bin/bash

[ $# -lt 2 ] && echo "Not enough arguments." && exit
[ -z $1 ] && echo "Naur" && exit
[ -z $2 ] && echo "Naur" && exit

if [[ -f $1 || -d $1 ]]; then
	if [ -L $1 ]; then
		echo "$1 already installed.";
	else
		echo "Backing up $1 and installing..." && mv $1 $1.bak && ln -sf $2 $1
	fi
else
	echo "$1 does not exist, installing..."
	ln -sf $2 $1
fi
