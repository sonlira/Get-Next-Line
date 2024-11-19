/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:35:57 by abaldelo          #+#    #+#             */
/*   Updated: 2024/11/19 14:57:48 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*set_line(char *line_buffer)
{
	char	*save;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	save = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*save == 0)
	{
		free(save);
		save = NULL;
	}
	line_buffer[i + 1] = 0;
	return (save);
}

static char	*fill_buffer(int fd, char *save, char *buffer)
{
	char	*tmp;
	ssize_t	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(save), NULL);
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = 0;
		if (!save)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, save, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	save = set_line(line);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	fd = open("read.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Open file filed");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
