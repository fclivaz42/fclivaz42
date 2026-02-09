/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassInfod.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:58:12 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:04:33 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOD_SERVER_HPP
# define INFOD_SERVER_HPP

#include "ClassBrightnessd.hpp"
#include "ClassVolumed.hpp"
#include "infod.hpp"
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/un.h>
#include <vector>

class InfoServer
{
	private:
		const pid_t					_pid;
		int							_sfd;
		Volumed						_volctl;
		Brightnessd					_brictl;
		std::vector<int>			_volcli;
		std::vector<int>			_bricli;
		struct sockaddr_un			_sockadr;
		std::vector<struct pollfd>	_clients;

	public:
		InfoServer(const pid_t pid, const std::string& socket_path);
		~InfoServer();

		int	boilerplate();
		int	loop();
		int	connect();
		int	accept_incoming();
		int	execute();
		int	forward();
		int	subscribe();
};

#endif // !INFOD_SERVER_HPP
