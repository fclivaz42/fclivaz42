# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:03:40 by fclivaz           #+#    #+#              #
#    Updated: 2025/04/17 16:55:44 by fclivaz          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

export MAKEFLAGS += --silent

PWD = $(shell pwd)

HOME = $(shell echo $$HOME)

UNAME = $(shell uname)

SHELL = /bin/bash

ifeq (${UNAME},Darwin)
	INAME = macOS
else
	INAME = $(shell grep "^NAME=" /etc/os-release | cut -d'"' -f2)
endif

all:
	echo "Usage: make install"

core:
	echo "Installing core files."
	chmod a+x ./helper.sh
	cd ${PWD}/home; \
	for file in *; do /bin/bash ../helper.sh ${HOME}/.$$file $$PWD/$$file; done
	mkdir -p ${HOME}/zshrc.d
	cd ${PWD}/zshrc.d; \
	for file in *; do /bin/bash ../helper.sh ${HOME}/zshrc.d/$$file $$PWD/$$file; done
	if [ ! -d ${HOME}/.tmux ]; then \
		echo "Cloning TPM..." && git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm; \
	else \
		echo "TPM already installed."; \
	fi
	echo "Installing config..."
	mkdir -p ${HOME}/.config
	file="mimeapps.list" && ./helper.sh ${HOME}/.config/$$file ${PWD}/config/$$file
	fld="bat" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="btop" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="fastfetch" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="starship" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld default.toml _*
	if [ ! -d ${HOME}/.config/nvim ]; then \
		echo "Cloning 42-Nvim..." && git clone git@github.com:fclivaz42/42-nvim.git ${HOME}/.config/nvim; \
		cd ${HOME}/.config/nvim && git switch personal; \
	else \
		echo "42-Nvim already installed."; \
	fi

graphical:
	fld="alacritty" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld alacritty.toml _*
	fld="kitty" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld kitty.conf _*
	fld="ghostty" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld config _*

clangd:
	fld="clangd" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld

ubuntu: core graphical clangd
	fld="cava" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld

macos: core graphical
	fld="clangd" && ./helper.sh ${HOME}/Library/Preferences/$$fld ${PWD}/config/$$fld

alpine: core clangd
	rm -rf ${HOME}/zshrc.d/zsh_brewconfig

arch: core graphical clangd
	rm -rf ${HOME}/zshrc.d/zsh_brewconfig
	fld="cava" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="dunst" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="eww" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="hypr" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld hyprland.conf __*
	fld="swappy" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="waybar" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld config.json _*
	fld="wlogout" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld layout _*
	fld="wofi" && ./folder.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld config _*
	echo "Copying/linking bin folder..."
	mkdir -p ~/bin
	cd ./bin
	fld="swwwd" && ./helper.sh ${HOME}/bin/$$fld ${PWD}/bin/$$fld && chmod a+x ${PWD}/bin/$$fld
	fld="hyprsave" && ./helper.sh ${HOME}/bin/$$fld ${PWD}/bin/$$fld && chmod a+x ${PWD}/bin/$$fld
	fld="powmenu" && ./helper.sh ${HOME}/bin/$$fld ${PWD}/bin/$$fld && chmod a+x ${PWD}/bin/$$fld
	fld="backall" && \
	if [ -f ${HOME}/bin/$$fld ]; then \
		echo "$$fld already installed."; \
	else \
		echo "Copying $$fld..."; \
		cp ${PWD}/bin/$$fld ${HOME}/bin/; \
	fi
	cp ${PWD}/bin/bwoop.oga ${HOME}/bin/

install:
	echo "Warning: This will replace your current configuration."
	read -p "Continue? (Y/N): " CONFIRM; \
	if [[ $$CONFIRM == [yY] || $$CONFIRM == [yY][eE][sS] ]]; then \
		if [[ "${INAME}" == "Arch Linux" ]]; then \
			echo "Installing for Arch."; \
			${MAKE} arch;\
		elif [[ "${INAME}" == "Alpine Linux" ]]; then \
			echo "Installing for Alpine."; \
			${MAKE} alpine;\
		elif [[ "${INAME}" == "Ubuntu" ]]; then \
			echo "Installing for Ubuntu."; \
			${MAKE} ubuntu;\
		elif [[ "${INAME}" == "macOS" ]]; then \
			echo "Installing for macOS."; \
			${MAKE} macos;\
		else \
			echo "Unsupported OS."; \
		fi; \
	fi

userjs:
	echo "Installing user.js..."
	find ~ -name "prefs.js" -exec dirname {} \; | xargs -I % bash -c "echo '%' && ln -sf '${PWD}/user.js' '%/user.js'"
