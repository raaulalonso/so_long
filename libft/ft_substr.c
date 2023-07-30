/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:22:16 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/12 22:11:25 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((ft_strlen(s) == 0) || (start >= ft_strlen(s)))
	{
		str = (char *)malloc(1 * sizeof(char));
		str[i] = '\0';
		return (str);
	}
	else if (len < (ft_strlen(s) - start))
		str = (char *)malloc((len + 1)
				* sizeof(char));
	else
		str = (char *)malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	if (!str)
		return (0);
	while ((s[start] != '\0') && (i < len))
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	printf("%s", ft_substr("FULL BULLSHIT", 400, 20));
	return 0; 
}*/
