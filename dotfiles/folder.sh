#!/bin/bash

[ $# -lt 4 ] && echo "Not enough arguments." && exit
[ -z $1 ] && echo "Naur" && exit
[ -z $2 ] && echo "Naur" && exit
[ -z $3 ] && echo "Naur" && exit
[ -z $4 ] && echo "Naur" && exit

if [ -d $1 ]; then
	if [[ ! -L $1/$3 && ! -L $1 ]]; then
		echo "Backing up $1..." && mv $1 $1.bak
		echo "Installing $1..."
		rm -rf $1; mkdir -p $1
		cd $2
		for file in *; do
			if [[ $file = $4 ]]; then
				cp $2/$file $1
			else
				ln -sf $2/$file $1/$file
			fi
		done
	elif [ -L $1 ]; then
			echo "$1 is already hard-linked."; exit
	else
		echo "$1 is already installed."; exit
	fi
else
	echo "Installing $1..."
	rm -rf $1; mkdir -p $1
	cd $2
	for file in *; do
		if [[ $file = $4 ]]; then
			cp $2/$file $1
		else
			ln -sf $2/$file $1/$file
		fi
	done
fi
