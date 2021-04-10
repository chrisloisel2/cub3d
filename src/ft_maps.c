/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:39:26 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perfect_cube(t_t *t)
{
	int		i;
	char	s[2];
	int		y;

	s[0] = ' ';
	s[1] = '\0';
	i = 0;
	y = 0;
	while (y < t->maxy - 1)
	{
		if (i < ft_strlen(t->tb[y]))
			i = ft_strlen(t->tb[y]);
		y++;
	}
	t->maxx = i;
	y = 0;
	while (y < t->maxy)
	{
		while (i > ft_strlen(t->tb[y]))
			ft_free_strjoin(t->tb[y], s, &t->tb[y]);
		y++;
	}
}

int		ft_get_player_two(char c, t_t *t)
{
	if (c == 'S')
	{
		t->planex = -0.66;
		t->planey = 0.0;
		t->diry = 1.0;
		t->dirx = 0.0;
		return (1);
	}
	if (c == 'W')
	{
		t->planex = 0.0;
		t->planey = -0.66;
		t->diry = 0.0;
		t->dirx = -1.0;
		return (1);
	}
	return (0);
}

int		ft_get_player(char c, t_t *t)
{
	if (c == 'N')
	{
		t->diry = -1.0;
		t->dirx = 0.0;
		t->planex = 0.66;
		t->planey = 0.0;
		return (1);
	}
	if (c == 'E')
	{
		t->planex = 0.00;
		t->planey = 0.66;
		t->diry = 0.0;
		t->dirx = 1.0;
		return (1);
	}
	return (ft_get_player_two(c, t));
}

void	ft_map_check(t_t *t)
{
	int x;
	int y;
	int r;

	r = 0;
	x = 0;
	y = 0;
	while (y < t->maxy)
	{
		while (x < t->maxx)
		{
			(t->tb[y][x] == ' ') ? t->tb[y][x] = '0' : 0;
			if (ft_get_player(t->tb[y][x], t) == 1)
			{
				r++;
				t->x = x + 0.5;
				t->y = y + 0.5;
				t->tb[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	(r != 1) ? t->error = 1 : 0;
}
