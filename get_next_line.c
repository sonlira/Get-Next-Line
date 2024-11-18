/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:35:57 by abaldelo          #+#    #+#             */
/*   Updated: 2024/11/18 12:39:17 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	read_bytes;
	char	buffer[BUFF_SIZE];

	read_bytes = read(fd, buffer, sizeof(buffer));
	write(1, buffer, read_bytes);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Open file filed");
		return (1);
	}
	get_next_line(fd);
	close(fd);
	return (0);
}
 