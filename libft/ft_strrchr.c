/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:02:21 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/12 22:23:34 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			str = ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
	{
		str = (char *)s;
		return (str + i);
	}
	return (str);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str = "horla mer llamo raul";
	printf("%s", ft_strrchr(str, 256));
	return (0);
}*/