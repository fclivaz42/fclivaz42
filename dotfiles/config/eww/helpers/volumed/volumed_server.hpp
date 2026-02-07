/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volumed_server.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:58:12 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/07 23:25:09 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOLUMED_SERVER_HPP
# define VOLUMED_SERVER_HPP

#include "volumed.hpp"
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/un.h>

class VolumeServer
{
	private:
		struct sockaddr_un	_sockaddr;
		const pid_t			_pid;
		int					_sfd;

	public:
		VolumeServer(const pid_t pid, const std::string& socket_path);
		~VolumeServer();

		int	boilerplate();
		int	loop();
		int	connect();
		int	cleanup();
};

#endif // !VOLUMED_SERVER_HPP
