/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:41 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:43 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
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
    num = ft_isdigit('4');
    printf("%d\n", num);
    return 0;
}*/
