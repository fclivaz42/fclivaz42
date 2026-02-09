/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infod.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:54:05 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 20:00:25 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOD_HPP
# define INFOD_HPP

#include <iostream>
#include <unistd.h>

#define XDG_ENV		"XDG_RUNTIME_DIR="
#define SOCKET_FILE	"/volumed.sock"
#define ERR_SOCK	"Could not create socket. Exiting."
#define ERR_BIND	"Could not bind to socket. Exiting."
#define ERR_LISTEN	"Could not listen on socket. Exiting."

#define VOL_SET 'v'
#define VOL_MUT 'm'
#define BRI_SET 'b'
#define START 's'

#endif // !INFOD_HPP
