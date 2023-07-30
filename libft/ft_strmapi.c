/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:42:09 by raalonso          #+#    #+#             */
/*   Updated: 2023/03/23 20:51:32 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < (unsigned int)ft_strlen(s))
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
	printf("%s", ft_strmapi("hola", prueba));
	return 0;
}*/