/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:37:29 by abaldelo          #+#    #+#             */
/*   Updated: 2024/10/15 15:27:51 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	if ((slen - start) < len)
		len = slen - start;
	str = (char *) malloc((len + 1) * 1);
	if (!str)
		return (NULL);
	i = 0;
	ft_strlcpy(str, (s + start), (len + 1));
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	dst = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	p;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	p = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[p])
	{
		str[i] = s2[p];
		p++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
