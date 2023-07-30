/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:00:10 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/13 17:40:02 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	i = 0;
	if (dstsize != 0)
	{
		while ((src[i] != '\0') && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str1 = "hola soy raul";
	char str2[14];
	printf("%zu", ft_strlcpy(str2, str1, 14));
	printf("%s", str2);
	return 0;
}*/
