/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:35:57 by abaldelo          #+#    #+#             */
/*   Updated: 2024/11/28 21:54:59 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	static char	*store = NULL;
	char		*line;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, buffer, store);
	if (!line)
		return (free(line), NULL);
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		store = ft_strdup(newline_pos + 1);
	}
	else
		store = NULL;
	return (line);
}

int	main(void)
{
	char *line;
	int	fd;

	fd = open("big_line_nl.txt", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s\n", line);
			free(line);
		}
		else
			break ;
	}
	// line = get_next_linee(fd);
	// printf("%s\n", line);
	// free(line);
	// line = get_next_linee(fd);
	// printf("%s", line);
	// free(line);
	close(fd);
	return (0);
}
