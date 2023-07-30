/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:43:04 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/07 01:01:32 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_number(const char *str, int i)
{
	int	j;
	int	num;

	j = 0;
	num = 0;
	while ((str[i + j] != '\0') && ((str[i + j] <= '9') && (str[i + j] >= '0')))
	{
		num = ((num * 10) + (str[i + j] - 48));
		j++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign++;
	}
	else if (str[i] == '+')
		i++;
	num = ft_number(str, i);
	if (sign == 1)
		return (num * -1);
	return (num);
}

/*#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *str = "  \n  -1322";
	printf("%d", ft_atoi(str));
	return 0;
}*/