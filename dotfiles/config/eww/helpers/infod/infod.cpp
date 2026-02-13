/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infod.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:31:36 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/13 21:20:22 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "infod.hpp"
#include "ClassInfod.hpp"
#include <cstring>

static inline bool check_socket(const std::string& socket_path, char mode)
{
	bool	ret = false;

	switch (mode)
	{
		case MODE_SERVER:
			ret = ! access(socket_path.c_str(), F_OK);
			break;
		case MODE_CLIENT:
			ret = access(socket_path.c_str(), F_OK);
			break;
	}
	if (ret)
		std::cout << ( mode == MODE_CLIENT ? ERR_SOCKET_ABSENT : ERR_SOCKET_EXISTS ) << std::endl;
	return ret;
}

static int	sub(char service, const std::string& socket_path)
{
	std::string	exec(std::format("{} {}", LISTEN, service));

	if (check_socket(socket_path, MODE_CLIENT))
		return ERR_SOCKET;

	std::cout << exec << std::endl;

	return SUCCESS;
}

static int	send_command(char **args, const std::string& socket_path)
{
	std::string	exec(std::format("{}", EXEC));

	if (check_socket(socket_path, MODE_CLIENT))
		return ERR_SOCKET;

	for (; *args != nullptr; ++args)
		exec.append(" ").append(*args);
	std::cout << exec << std::endl;

	return SUCCESS;
}

static int	start_server(const std::string& socket_path)
{
	int				rcode;
	pid_t			pid;

	if (check_socket(socket_path, MODE_SERVER))
		return ERR_SOCKET;

	pid = fork();
	if (pid != 0)
	{
		std::cout << "volumed starting... " << std::endl;
		return SUCCESS;
	}

	InfoServer	server(getpid(), socket_path.c_str());

	if (server.boilerplate())
		return 1;
	rcode = server.loop();

	return rcode;
}

int	main(int ac, char *av[], char *env[])
{
	std::string		socket_path;

	if (ac < 2)
	{
		std::cerr << USAGE_INFOD << START << USAGE_START << std::endl
			<< USAGE_ALTER << LISTEN << USAGE_LISTEN << std::endl
			<< USAGE_ALTER << VOL_SET << USAGE_VOLSET << std::endl
			<< USAGE_ALTER << VOL_MUT << USAGE_VOLMUT << std::endl
			<< USAGE_ALTER << BRI_SET << USAGE_BRISET << std::endl;
		return ERR_USAGE;
	}

	for (size_t i = 0; env[i] != NULL; i++)
	{
		if (! strncmp(env[i], XDG_ENV, strlen(XDG_ENV)))
		{
			socket_path = (strchr(env[i], '=') + 1);
			break;
		}
	}

	if (socket_path.size() == 0)
	{
		std::cerr << "XDG_RUNTIME_DIR not found. Exiting." << std::endl;
		return ERR_ENV;
	}

	socket_path.append(SOCKET_FILE);

	switch (av[1][0])
	{
		case START:
			if (ac > 2)
			{
				std::cerr << USAGE_INFOD << START << USAGE_START << std::endl;
				break;
			}
			return start_server(socket_path);

		case LISTEN:
			if (ac < 3 || ac > 3 || strlen(av[2]) > 1)
			{
				std::cerr << USAGE_INFOD << LISTEN << USAGE_LISTEN << std::endl;
				break;
			}
			return sub(av[2][0], socket_path);

		case VOL_SET:
			if (ac < 3 || ac > 3)
			{
				std::cerr << USAGE_INFOD << VOL_SET << USAGE_VOLSET << std::endl;
				break;
			}
			return send_command(&av[1], socket_path);

		case VOL_MUT:
			if (ac > 2)
			{
				std::cerr << USAGE_INFOD << VOL_MUT << USAGE_VOLMUT << std::endl;
				break;
			}
			return send_command(&av[1], socket_path);

		case BRI_SET:
			if (ac < 3 || ac > 4)
			{
				std::cerr << USAGE_INFOD << BRI_SET << USAGE_BRISET << std::endl;
				break;
			}
			return send_command(&av[1], socket_path);

		default:
			std::cerr << "Incorrect parameter." << std::endl;
	}
	return ERR_USAGE;
}
