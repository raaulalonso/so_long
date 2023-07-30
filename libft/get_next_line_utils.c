/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:04:27 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/28 03:10:18 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_v2(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*long_stash;

	if (stash == NULL)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	long_stash = malloc(sizeof(char)
			* ((ft_strlen(stash) + ft_strlen(buffer)) + 1));
	if (long_stash == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			long_stash[i] = stash[i];
	while (buffer[j] != '\0')
		long_stash[i++] = buffer[j++];
	long_stash[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (long_stash);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_lines(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (new_stash == NULL)
		return (NULL);
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
