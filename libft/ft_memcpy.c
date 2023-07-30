/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:28 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/07 02:09:48 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	if ((!dst) && (!src))
		return (0);
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "hola adios";
	memcpy(str + 2, str + 1, 3);
	printf("%s", str);
	return 0;
}*/