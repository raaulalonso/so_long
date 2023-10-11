/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:19 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 20:22:19 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convers(char *print, int i, va_list *param, int *count)
{
	if ((print[i] != '\0') && (print[i + 1] == 's'))
		*count += (ft_putstr_fd(va_arg(*param, char *), 1) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == 'c'))
		*count += (ft_putchar_fd(va_arg(*param, int), 1) - 2);
	else if ((print[i] != '\0') && ((print[i + 1] == 'i')
			|| (print[i + 1] == 'd')))
		*count += (ft_putnbr_fd(va_arg(*param, int), 1) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == 'u'))
		*count += (ft_putnbr_unsigned(va_arg(*param, unsigned int)) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == 'p'))
		*count += (ft_putmem(va_arg(*param, void *)) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == 'x'))
		*count += (ft_puthex(va_arg(*param, unsigned int), 1) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == 'X'))
		*count += (ft_puthex(va_arg(*param, unsigned int), 2) - 2);
	else if ((print[i] != '\0') && (print[i + 1] == '%'))
		*count -= ft_putchar_fd('%', 1);
}

int	ft_printf(char const *print, ...)
{
	int		i;
	int		count;
	va_list	param;

	va_start(param, print);
	i = 0;
	count = 0;
	while (print[i] != '\0')
	{
		while ((print[i] != '%') && (print[i] != '\0'))
		{
			write(1, &print[i], 1);
			i++;
		}
		if (print[i] == '\0')
			break ;
		convers((char *)print, i, &param, &count);
		i += 2;
	}
	va_end(param);
	return (i + count);
}
