/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volumed_server.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:12:55 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/07 23:20:58 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "volumed_server.hpp"

VolumeServer::VolumeServer(const pid_t pid, const std::string& socket_path) : _pid(pid)
{
	bzero(&(this->_sockaddr), sizeof(struct sockaddr_un));
	this->_sockaddr.sun_family = AF_UNIX;
	strncpy(this->_sockaddr.sun_path, socket_path.c_str(), sizeof(this->_sockaddr.sun_path));
}

VolumeServer::~VolumeServer()
{}

int	VolumeServer::boilerplate()
{
	this->_sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (this->_sfd <= 0)
	{
		std::cerr << ERR_SOCK << std::endl;
		return 1;
	}
	if (bind(this->_sfd, (struct sockaddr *) &(this->_sockaddr), sizeof(struct sockaddr_un)) < 0)
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

int VolumeServer::loop()
{
	std::cout << "looping! yippie :)" << std::endl;

	while (poll(NULL, 0, -1))
	{

	}
	return 0;
}

int VolumeServer::cleanup()
{
	std::cout << "Cleaning up..." << std::endl;
	if (unlink(this->_sockaddr.sun_path) < 0)
		std::cerr << strerror(errno) << " " << this->_sockaddr.sun_path << std::endl;
	close(this->_sfd);
	return 0;
}
