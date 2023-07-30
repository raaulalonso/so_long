/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:52:44 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/07 01:04:39 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strcpymod(char *str, char *s, int k, int start)
{
	int	i;

	i = 0;
	while (i < k)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
}

static int	countwords(char *str, char c)
{
	int	i;
	int	f;
	int	wnum;

	i = 0;
	f = 0;
	wnum = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (f == 0)
				wnum++;
			f = 1;
		}
		else
			f = 0;
		i++;
	}
	return (wnum);
}

static int	wordmem(int wnum, char *s, char c, char **str)
{
	int	i;
	int	word;
	int	k;

	i = 0;
	word = 0;
	k = 0;
	while (word < wnum)
	{
		while (s[i] == c)
			i++;
		k = i;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		str[word] = (char *)malloc(((i - k) + 1) * sizeof(char));
		if (!str[word])
			return (0);
		strcpymod(str[word], s, (i - k), k);
		word++;
	}
	str[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wnum;
	char	**str;

	wnum = countwords((char *)s, c);
	str = (char **)malloc((wnum + 1) * sizeof(char *));
	if (!str)
		return (0);
	if (wordmem(wnum, (char *)s, c, str) == 1)
		return (str);
	else
		return (0);
}

/*#include <stdio.h>
int main(void)
{
	int i;
	char **str2;
	
	i = 0;
	str2 = ft_split("ho a", ' ');
	while (i < 2)
	{
		printf("%s", str2[i]);
		printf("\n");
		i++;
	}
	return 0;
}*/