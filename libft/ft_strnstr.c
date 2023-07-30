/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:59:16 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/12 20:42:04 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		while (((haystack[i + j] == needle[j]) && ((i + j) < len))
			&& ((haystack[i + j] != '\0') && (needle[j] != '\0')))
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		else
		i++;
		j = 0;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str = "hola soy raul";
	char *str2 = "soy";
	printf("%s", ft_strnstr(str, str2, 14));
	return 0;
}*/