/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infod.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:54:05 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/13 21:14:06 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOD_HPP
# define INFOD_HPP

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#define XDG_ENV				"XDG_RUNTIME_DIR="
#define SOCKET_FILE			"/volumed.sock"
#define ERR_SOCK			"Could not create socket. Exiting."
#define ERR_BIND			"Could not bind to socket. Exiting."
#define ERR_LISTEN			"Could not listen on socket. Exiting."
#define ERR_SOCKET_EXISTS	"Socket file already exists, server is already running."
#define ERR_SOCKET_ABSENT	"Socket file does not exist! Is server alive?"

#define USAGE_INFOD		"Usage: 'infod "
#define USAGE_ALTER		"     : 'infod "
#define USAGE_START		"' to start the server."
#define USAGE_LISTEN	" < b | v >' to listen to brightness or volume events."
#define USAGE_VOLSET	" <volume(%)>' to set the volume (%)."
#define USAGE_VOLMUT	"' to toggle mute."
#define USAGE_BRISET	" <brightness(+-%)> (device)' to set the brightness (%)."

#define VOL_SET	'v'
#define VOL_MUT	'm'
#define BRI_SET	'b'
#define LISTEN	'l'
#define START	's'
#define EXEC	'x'

#define MODE_SERVER 0
#define MODE_CLIENT 1

enum error_codes
{
	SUCCESS = EXIT_SUCCESS,
	ERR_USAGE,
	ERR_ENV,
	ERR_SOCKET,
	ERR_SERVER,
};

#endif // !INFOD_HPP
