/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:39:41 by raalonso          #+#    #+#             */
/*   Updated: 2023/05/08 21:08:42 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, 1);
		count += ft_putnbr_fd(n % 10, 1);
	}
	else
	{
		num = (n + 48);
		count += write (1, &num, 1);
	}
	return (count);
}
