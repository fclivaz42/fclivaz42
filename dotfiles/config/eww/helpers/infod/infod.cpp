/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infod.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:31:36 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 20:13:13 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "infod.hpp"
#include "ClassInfod.hpp"

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

	InfoServer	server(getpid(), socket_path.c_str());

	if (server.boilerplate())
		return 1;
	rcode = server.loop();

	return rcode;
}

int	main(int ac, char *av[], char *env[])
{
	if (ac < 2)
	{
		std::cerr << "Usage: 'infod " << START <<"' to start the server." << std::endl
			<< "     : 'infod " << VOL_SET << " <volume(%)>' to set the volume (%)." << std::endl
			<< "     : 'infod " << VOL_MUT << "' to toggle mute." << std::endl
			<< "     : 'infod " << BRI_SET << " <brightness(+-%)> <device>' to set the brightness (%)." << std::endl;
		return 1;
	}

	switch (av[1][0])
	{
		case START:
			if (ac > 2)
			{
				std::cerr << "Usage: 'infod " << START <<"' to start the server." << std::endl;
				return 1;
			}
			return start_server(env);

		case VOL_SET:
			if (ac < 3 || ac > 3)
			{
				std::cerr << "Usage: 'infod " << VOL_SET << " <volume(%)>' to set the volume (%)." << std::endl;
				return 1;
			}
			break;

		case VOL_MUT:
			if (ac > 2)
			{
				std::cerr << "Usage: 'infod " << VOL_MUT << "' to toggle mute." << std::endl;
				return 1;
			}
			break;

		case BRI_SET:
			if (ac < 4 || ac > 4)
			{
				std::cerr << "Usage: 'infod " << BRI_SET << " <brightness(+-%)> <device>' to set the brightness (%)." << std::endl;
				return 1;
			}
			break;

		default:
			std::cerr << "Incorrect parameter." << std::endl;
			return 1;
	}
	return 0;
}
