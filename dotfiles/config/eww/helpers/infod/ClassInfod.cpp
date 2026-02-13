/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassInfod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:12:55 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/13 20:47:48 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassInfod.hpp"

InfoServer::InfoServer(const pid_t pid, const std::string& socket_path) : _pid(pid)
{
	bzero(&(this->_sockadr), sizeof(struct sockaddr_un));
	this->_sockadr.sun_family = AF_UNIX;
	strncpy(this->_sockadr.sun_path, socket_path.c_str(), sizeof(this->_sockadr.sun_path));
}

int	InfoServer::boilerplate()
{
	this->_sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (this->_sfd <= 0)
	{
		std::cerr << ERR_SOCK << std::endl;
		return 1;
	}
	if (bind(this->_sfd, (struct sockaddr *) &(this->_sockadr), sizeof(struct sockaddr_un)) < 0)
	{
		std::cerr << ERR_BIND << std::endl;
		return 1;
	}
	if (listen(this->_sfd, 64) < 0)
	{
		std::cerr << ERR_LISTEN << std::endl;
		return 1;
	}

	_volcli.reserve(4);
	_bricli.reserve(4);
	_clients.reserve(4);
	return 0;
}

int InfoServer::loop()
{
	std::cout << "looping! yippie :)" << std::endl;

	// TODO: set signal handler here. We want to cleanly exit on SIGTERM/SIGQUIT/SIGINT and the like.

	_clients.push_back({_sfd, POLLIN, 0});

	while (poll(_clients.data(), _clients.size(), -1))
	{
		if (_clients[0].revents & POLLIN)
			;
			// accept_incoming();
		for (size_t i = 1; i < _clients.size(); i++)
		{
			// if (_clients[i].revents & POLLIN)
			// 	client_read(); which will figure out if the client is [e]xecuting or [s]ubscribing.
			// 	Send reply to execution and close immediately, close subscribed only on disconnect.
			// else if (_clients[i].revents & POLLOUT) // dont really check for pollout though lmao
			// 	forward();
		}
	}
	return 0;
}

InfoServer::~InfoServer()
{
	std::cout << "Cleaning up..." << std::endl;
	if (unlink(this->_sockadr.sun_path) < 0)
		std::cerr << strerror(errno) << " " << this->_sockadr.sun_path << std::endl;
	close(this->_sfd);
}
