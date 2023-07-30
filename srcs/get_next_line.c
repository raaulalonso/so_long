/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:04:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/28 03:17:51 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	*get_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (read_bytes != 0 && ft_strchr(stash, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_v2(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_lines(stash);
	stash = clean_stash(stash);
	return (line);
}

/*# include <fcntl.h>
int main(void)
{
	int fd;
	char *line;

	fd = open("font.c", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
}*/

/*int main(void)
{
	char *line;

    while ((line = get_next_line(0)) != NULL)
    {
        printf("%s", line);
    }

    return 0;
}*/
