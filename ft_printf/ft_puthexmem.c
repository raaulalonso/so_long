/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:20:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/15 18:57:35 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cases2(uintptr_t n, int flag, int count)
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

int	ft_puthexmem(uintptr_t n, int flag)
{
	char	num;
	int		count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthexmem(n / 16, flag);
		count += ft_puthexmem(n % 16, flag);
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
			count += cases2(n, flag, count);
		}
	}
	return (count);
}
