# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:03:40 by fclivaz           #+#    #+#              #
#    Updated: 2024/11/06 00:23:14 by fclivaz          ###   LAUSANNE.ch        #
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

install:
	@if [[ "${INAME}" == "Arch Linux" ]]; then \
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
	fi

all:
	echo "Usage: make install"
