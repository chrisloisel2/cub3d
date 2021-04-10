/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:30:35 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/29 00:02:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(char const *s, char c)
{
	int		total;
	int		test;

	total = 0;
	test = 0;
	while (*s)
	{
		if (*s != c && test == 0)
		{
			total++;
			test = 1;
		}
		else if (*s == c && test)
			test = 0;
		s++;
	}
	return (total);
}

int		ft_fill(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_clean(char **tab, int limit)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		y;
	int		tmp;

	i = 0;
	tmp = 0;
	y = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	while (i < ft_count(s, c))
	{
		while (s[tmp] == c)
			tmp++;
		if (!(tab[i] = malloc(sizeof(char) * ft_fill(s + tmp, c) + 1)))
			return (ft_clean(tab, i));
		while (s[tmp] != c && s[tmp] != '\0')
			tab[i][y++] = s[tmp++];
		tab[i++][y] = '\0';
		y = 0;
	}
	tab[i] = NULL;
	return (tab);
}
