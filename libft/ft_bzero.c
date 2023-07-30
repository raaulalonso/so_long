/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:14:00 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/08 23:54:10 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*pt;

	pt = (char *)s;
	i = 0;
	if (n > 0)
	{
		while (i != n)
		{
			pt[i] = '\0';
			i++;
		}
	}
}

/*#include <strings.h>
#include <stdio.h>
int main(void)
{
	char str[] = "holaadios";
	ft_bzero(&str, 4);
	printf("%s", str);
	return 0;
}*/