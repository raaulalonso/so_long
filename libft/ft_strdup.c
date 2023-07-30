/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:25:19 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/13 20:05:58 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = "hola soy raul";
	printf("%s", ft_strdup(str));
	return 0;
}*/