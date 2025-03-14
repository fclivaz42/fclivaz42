/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:13:40 by fclivaz           #+#    #+#             */
/*   Updated: 2025/03/12 19:50:38 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <math.h>

#define BUFSIZE 1024

int	main(int ac, char *av[])
{
	float	entr;
	char	buf[BUFSIZE + 1];
	char	*line;
	int		sleeptime, fd;
	size_t	bytes;

	if (ac < 2)
		return 1;
	fd = open("/proc/net/wireless", O_RDONLY);
	sleeptime = atoi(av[1]);
	if (fd <= 0)
		return 1;
	bytes = 1;
	while (bytes >= 0)
	{
		bzero(buf, BUFSIZE);
		bytes = read(fd, buf, BUFSIZE);
		if (bytes <= 0)
		{
			if (lseek(fd, 0, SEEK_SET) < 0)
				return 1;
			sleep(sleeptime);
			continue ;
		}
		buf[BUFSIZE] = 0;
		line = strstr(buf, "wlan0:");
		if (line)
			line = strchr(line, '-');
		if (line)
			entr = strtod(line, NULL);
		else
			entr = -90;
		printf("%f\n", 105 - exp((-entr - pow(10, 0.1) ) / (20 - pow(10, 0.1))));
		fflush(NULL);
		sleep(sleeptime);
		lseek(fd, 0, SEEK_SET);
	}
	close(fd);
	return 0;
}
