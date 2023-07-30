/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:03:51 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/12 22:19:12 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_concatenate(char *str, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(((s1len + s2len) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = ft_concatenate(str, s1, s2);
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	printf("%s", ft_strjoin("hola", ""));
	return 0;
}*/
