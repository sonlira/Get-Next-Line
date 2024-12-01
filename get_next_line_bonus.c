/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:35:57 by abaldelo          #+#    #+#             */
/*   Updated: 2024/12/01 10:20:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_buffer(int fd, char *buffer, char *store)
{
	char	*tmp;
	ssize_t	read_bytes;

	tmp = NULL;
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!store)
			store = ft_strdup("");
		tmp = ft_strjoin(store, buffer);
		free(store);
		store = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*store[4095];
	char		*line;
	char		*line_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, buffer, store[fd]);
	if (!line)
		return (free(store[fd]), store[fd] = NULL, NULL);
	line_pos = ft_strchr(line, '\n');
	if (line_pos && line_pos[1] != '\0')
	{
		store[fd] = ft_strdup(line_pos + 1);
		line_pos[1] = '\0';
	}
	else
		store[fd] = NULL;
	return (line);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;

	fd1 = open("read.txt", O_RDONLY);
	fd2 = open("text.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (1);
	while (1)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("fd 1: %s\n", line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line)
		{
			printf("fd 2: %s\n", line);
			free(line);
		}
		else
			break ;
	}
	close(fd1);
	close(fd2);
	return (0);
}
*/