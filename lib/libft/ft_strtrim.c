/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:58:19 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/29 01:17:58 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_last(char const *s1, char const *set)
{
	int		i;
	int		check;
	int		o;
	int		t;

	t = 0;
	o = 0;
	check = 0;
	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && t != -1)
	{
		while (set[o] != '\0' && t == 0)
		{
			if (s1[i] == set[o])
			{
				check++;
				t = 1;
			}
			o++;
		}
		t--;
		o = 0;
		i--;
	}
	return (check);
}

int		ft_first(char const *s1, char const *set)
{
	int		i;
	int		check;
	int		o;
	int		t;

	o = 0;
	check = 0;
	i = 0;
	while (s1[i] != '\0' && check == i)
	{
		t = 0;
		while (set[o] != '\0')
		{
			if (s1[i] == set[o] && t == 0)
			{
				check++;
				t++;
			}
			o++;
		}
		o = 0;
		i++;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		len;
	int		y;

	if (!s1 || !set)
		return (NULL);
	y = 0;
	i = ft_first(s1, set);
	len = ft_strlen(s1) - (ft_first(s1, set) + ft_last(s1, set));
	if (len < 0)
		len = 0;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (y < len)
	{
		s[y] = s1[i];
		y++;
		i++;
	}
	s[y] = '\0';
	return (s);
}
