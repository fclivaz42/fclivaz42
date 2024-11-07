# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:03:40 by fclivaz           #+#    #+#              #
#    Updated: 2024/11/07 01:53:13 by fclivaz          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

export MAKEFLAGS += --silent
#
UNAME = $(shell uname)

ifeq (${UNAME},Darwin)
	INAME = macOS
else
	INAME = $(shell grep "^NAME=" /etc/os-release | cut -d'"' -f2)
endif

all:
	echo "Usage: make install"

arch:
	echo "installing ZSH environment..."
	ln -sf $(shell pwd)/home/zshrc $$HOME/.zshrc
	ln -sf $(shell pwd)/home/zsh_aliases $$HOME/.zsh_aliases
	ln -sf $(shell pwd)/home/zsh_exports $$HOME/.zsh_exports
	ln -sf $(shell pwd)/home/zsh_plugins $$HOME/.zsh_plugins
	echo "installing Git environment..."
	ln -sf $(shell pwd)/home/gitconfig $$HOME/.gitconfig
	ln -sf $(shell pwd)/home/git_global_ignore $$HOME/.git_global_ignore
	echo "installing tmux file..."
	ln -sf $(shell pwd)/home/tmux.conf $$HOME/.tmux.conf
	echo "installing vimrc..."
	ln -sf $(shell pwd)/home/vimrc $$HOME/.vimrc

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
