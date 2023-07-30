/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:46 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/11 18:19:04 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c <= 127) && (c >= 0))
	{
		return (1);
	}
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int num;
	num = ft_isascii('d');
	printf("%d\n", num);
	return 0;
}*/