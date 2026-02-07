/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volumed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:54:05 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/07 21:02:43 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOLUMED_HPP
# define VOLUMED_HPP

#include <iostream>
#include <unistd.h>

#define XDG_ENV		"XDG_RUNTIME_DIR="
#define SOCKET_FILE	"/volumed.sock"
#define ERR_SOCK	"Could not create socket. Exiting."
#define ERR_BIND	"Could not bind to socket. Exiting."
#define ERR_LISTEN	"Could not listen on socket. Exiting."

#endif // !VOLUMED_HPP
