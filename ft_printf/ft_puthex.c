/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:38:53 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/15 19:51:28 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cases(unsigned int n, int flag, int count)
{
	char	num;

	if (flag == 1)
	{
		num = (n + 87);
		count += write (1, &num, 1);
	}
	else if (flag == 2)
	{
		num = (n + 55);
		count += write (1, &num, 1);
	}
	return (count);
}

int	ft_puthex(unsigned int n, int flag)
{
	char	num;
	int		count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthex(n / 16, flag);
		count += ft_puthex(n % 16, flag);
	}
	else
	{
		if (n < 10)
		{
			num = (n + 48);
			count += write (1, &num, 1);
		}
		else
		{
			count += cases(n, flag, count);
		}
	}
	return (count);
}
