/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:35:43 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/11 18:45:01 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = 64;
	printf("%d", toupper(c));
	return 0;
}*/