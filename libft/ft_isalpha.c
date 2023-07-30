/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:51 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:53 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
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
    num = isalpha('b');
    printf("%d\n", num);
    return 0;
}*/
