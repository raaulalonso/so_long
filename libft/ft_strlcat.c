/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:19:53 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/13 19:46:08 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (dstsize < i)
		return (dstsize + j);
	j = 0;
	while (((src[j] != '\0') && (i < (dstsize - 1))) && (dstsize > 0))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (src[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
    int num;
    char str1[] = "hola soy ";
    char str2[] = "raul";
    
    num = ft_strlcat(str1, str2, 15);
    printf("%s\n", str1);
    printf("%d", num);
    return 0;
}*/