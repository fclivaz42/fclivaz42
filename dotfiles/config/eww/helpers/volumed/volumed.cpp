/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volumed.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:31:36 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/07 21:18:30 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "volumed_server.hpp"

int start_server(char *env[])
{
	int				rcode;
	pid_t			pid;
	std::string		socket_path;

	for (size_t i = 0; env[i] != NULL; i++)
	{
		if (! strncmp(env[i], XDG_ENV, strlen(XDG_ENV)))
		{
			socket_path = (strchr(env[i], '=') + 1);
			break;
		}
	}

	socket_path.append(SOCKET_FILE);

	if (access(socket_path.c_str(), F_OK) == 0)
	{
		std::cerr << "Socket file already exists, server is already running." << std::endl;
		return 1;
	}
	pid = fork();
	if (pid != 0)
	{
		std::cout << "volumed starting... " << std::endl;
		return 0;
	}

	VolumeServer	server(getpid(), socket_path.c_str());

	if (server.boilerplate())
		return 1;
	rcode = server.loop();
	rcode = server.cleanup();

	return rcode;
}

int	main(int ac, char *av[], char *env[])
{
	if (ac < 2 || ac > 3)
	{
		std::cerr << "Usage: volumed < s | i / d / m > <volume>" << std::endl;
		return 1;
	}

	switch (av[1][0])
	{
		case 's':
			return start_server(env);

		case 'i':
		case 'd':
			break;

		case 'm':
			break;

		default:
			std::cerr << "Incorrect parameter." << std::endl;
			return 1;
	}
	return 0;
}
