/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:55 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:57 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c > 47) && (c < 58))
	{
		return (1);
	}
	else if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
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
    num = isalnum('+');
    printf("%d\n", num);
    return 0;
}*/
