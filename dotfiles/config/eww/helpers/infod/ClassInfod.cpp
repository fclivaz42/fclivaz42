/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassInfod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:12:55 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:02:53 by fclivaz          ###   LAUSANNE.ch       */
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

	return 0;
}

int InfoServer::loop()
{
	std::cout << "looping! yippie :)" << std::endl;

	while (poll(NULL, 0, -1))
	{
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
