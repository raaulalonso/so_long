/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:35:41 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/12 20:52:23 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	calculatelen(char s1, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	k;
	size_t	start;
	size_t	s1len;
	size_t	end;

	s1len = ft_strlen(s1);
	end = (ft_strlen(s1) - 1);
	k = 0;
	while (calculatelen(s1[k++], (char *)set) == 1)
		s1len--;
	start = (ft_strlen(s1) - s1len);
	if (s1len != 0)
	{
		while (calculatelen(s1[end--], (char *)set) == 1)
			s1len--;
	}
	str = ft_substr(s1, start, s1len);
	if (!str)
		return (0);
	return (str);
}

/*int main(void)
{
	printf("%s", ft_strtrim("hola", "hola"));
	return 0;
}*/