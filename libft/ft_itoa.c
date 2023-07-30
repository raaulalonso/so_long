/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:07:07 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/07 01:02:09 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	reverse(long long num, int len)
{
	long long	rev;
	int			i;

	i = 0;
	rev = 0;
	while (i < len)
	{
		rev *= 10;
		rev += (num % 10);
		num *= 0.1;
		i++;
	}
	return (rev);
}

static void	numtostr(char *str, long long num, int nlen, int minus)
{
	int	i;

	i = 0;
	if (minus == 1)
	{
		str[i] = '-';
		nlen++;
		i++;
	}
	while (i < nlen)
	{
		str[i] = ((num % 10) + 48);
		num *= 0.1;
		i++;
	}
	str[i] = '\0';
}

static int	numlen(long long num)
{
	int	nlen;

	nlen = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = (num * 0.1);
		nlen++;
	}
	return (nlen);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			minus;
	int			nlen;
	long long	num;

	num = (long long)n;
	minus = 0;
	if (num < 0)
	{
		minus++;
		num *= -1;
	}
	nlen = numlen(num);
	if (minus == 1)
		str = (char *)malloc((nlen + 2) * sizeof(char));
	else
		str = (char *)malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (0);
	num = reverse(num, nlen);
	numtostr(str, num, nlen, minus);
	return (str);
}

/*int main(void)
{
	printf("%s", ft_itoa(-65867));
	return 0;
}*/