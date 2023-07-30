/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:36 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:38 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c > 31) && (c < 127))
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
	num = ft_isprint('d');
	printf("%d\n", num);
	return 0;
}*/
