# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:03:40 by fclivaz           #+#    #+#              #
#    Updated: 2024/11/08 04:38:11 by fclivaz          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

export MAKEFLAGS += --silent

PWD = $(shell pwd)

HOME = $(shell echo $$HOME)

UNAME = $(shell uname)

ifeq (${UNAME},Darwin)
	INAME = macOS
else
	INAME = $(shell grep "^NAME=" /etc/os-release | cut -d'"' -f2)
endif

all:
	echo "Usage: make install"

arch:
	echo "Installing dotfiles..."
	chmod a+x ./helper.sh
	cd ${PWD}/home; \
	for file in *; do /bin/bash ../helper.sh ${HOME}/.$$file $$PWD/$$file; done
	if [ ! -d ${HOME}/.tmux ]; then \
		echo "Cloning TPM..." && git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm; \
	else \
		echo "TPM already installed."; \
	fi
	# rm -rf ${HOME}/.zsh_brewconfig
	echo "Installing config..."
	fld="bat" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="btop" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="cava" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="clangd" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="dunst" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="eww" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="fastfetch" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="wlogout" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	fld="wofi" && ./helper.sh ${HOME}/.config/$$fld ${PWD}/config/$$fld
	if [ ! -d ${HOME}/.config/nvim ]; then \
		echo "Cloning 42-Nvim..." && git clone git@github.com:fclivaz42/42-nvim.git ${HOME}/.config/nvim; \
		cd ${HOME}/.config/nvim && git switch personal; \
	else \
		echo "42-Nvim already installed."; \
	fi
	fld="waybar" && \
	if [ -d ${HOME}/.config/$$fld ]; then \
		if [[ ! -L ${HOME}/.config/$$fld/config.json && ! -L ${HOME}/.config/$$fld ]]; then \
			echo "Backing up $$fld..." && mv ${HOME}/.config/$$fld ${HOME}/.config/$$fld.bak; \
			echo "Installing $$fld..."; \
			rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
			cd ${PWD}/config/$$fld/; \
			for file in *; do \
				if [[ $$file = _* ]]; then \
					cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
				else \
					ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
				fi ; \
			done; \
		elif [ -L ${HOME}/.config/$$fld ]; then \
				echo "$$fld is already hard-linked."; exit; \
		else \
			echo "$$fld is already installed."; exit; \
		fi ; \
	else \
		echo "Installing $$fld..."; \
		rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
		cd ${PWD}/config/$$fld/; \
		for file in *; do \
			if [[ $$file = _* ]]; then \
				cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
			else \
				ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
			fi ; \
		done; \
	fi
	fld="hypr" && \
	if [ -d ${HOME}/.config/$$fld ]; then \
		if [[ ! -L ${HOME}/.config/$$fld/hyprland.conf && ! -L ${HOME}/.config/$$fld ]]; then \
			echo "Backing up $$fld..." && mv ${HOME}/.config/$$fld ${HOME}/.config/$$fld.bak; \
			echo "Installing $$fld..."; \
			rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
			cd ${PWD}/config/$$fld/; \
			for file in *; do \
				if [[ $$file = __* ]]; then \
					cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
				else \
					ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
				fi ; \
			done; \
		elif [ -L ${HOME}/.config/$$fld ]; then \
				echo "$$fld is already hard-linked."; exit; \
		else \
			echo "$$fld is already installed."; exit; \
		fi ; \
	else \
		echo "Installing $$fld..."; \
		rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
		cd ${PWD}/config/$$fld/; \
		for file in *; do \
			if [[ $$file = __* ]]; then \
				cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
			else \
				ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
			fi ; \
		done; \
	fi
	fld="kitty" && \
	if [ -d ${HOME}/.config/$$fld ]; then \
		if [[ ! -L ${HOME}/.config/$$fld/kitty.conf && ! -L ${HOME}/.config/$$fld ]]; then \
			echo "Backing up $$fld..." && mv ${HOME}/.config/$$fld ${HOME}/.config/$$fld.bak; \
			echo "Installing $$fld..."; \
			rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
			cd ${PWD}/config/$$fld/; \
			for file in *; do \
				if [[ $$file = _* ]]; then \
					cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
				else \
					ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
				fi ; \
			done; \
		elif [ -L ${HOME}/.config/$$fld ]; then \
				echo "$$fld is already hard-linked."; exit; \
		else \
			echo "$$fld is already installed."; exit; \
		fi ; \
	else \
		echo "Installing $$fld..."; \
		rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
		cd ${PWD}/config/$$fld/; \
		for file in *; do \
			if [[ $$file = _* ]]; then \
				cp ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld; \
			else \
				ln -sf ${PWD}/config/$$fld/$$file ${HOME}/.config/$$fld/$$file; \
			fi ; \
		done; \
	fi
	fld="starship" && \
	if [ -d ${HOME}/.config/$$fld ]; then \
		if [ ! -L ${HOME}/.config/$$fld/default.toml ]; then \
			echo "Backing up $$fld..." && mv ${HOME}/.config/$$fld ${HOME}/.config/$$fld.bak; \
			echo "Installing $$fld..."; \
			rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
			ln -sf ${PWD}/config/$$fld.toml ${HOME}/.config/$$fld/default.toml; \
			cp ${PWD}/config/$$fld.toml ${HOME}/.config/$$fld/starship.toml; \
			echo "$$fld... installed. Remember to edit the config!"; \
		elif [ -L ${HOME}/.config/$$fld ]; then \
				echo "$$fld is already hard-linked."; exit; \
		else \
			echo "$$fld is already installed."; exit; \
		fi ; \
	else \
		echo "Installing $$fld..."; \
		rm -rf ${HOME}/.config/$$fld; mkdir ${HOME}/.config/$$fld; \
		ln -sf ${PWD}/config/$$fld.toml ${HOME}/.config/$$fld/default.toml; \
		cp ${PWD}/config/$$fld.toml ${HOME}/.config/$$fld/starship.toml; \
		echo "$$fld... installed. Remember to edit the config!"; \
	fi
	echo "Copying bin folder..."
	cp -r bin/ ~/

install:
	echo "Warning: This will replace your current configuration."
	read -p "Continue? (Y/N): " CONFIRM; \
	if [[ $$CONFIRM == [yY] || $$CONFIRM == [yY][eE][sS] ]]; then \
		if [[ "${INAME}" == "Arch Linux" ]]; then \
			echo "Installing for Arch."; \
			${MAKE} arch;\
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
	find ~ -name "prefs.js" -exec dirname {} \; | xargs -I % bash -c "echo % && ln -sf ${PWD}/user.js %/user.js"
