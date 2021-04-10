/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:38:39 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_search_map(t_t *t)
{
	ft_perfect_cube(t);
	ft_map_check(t);
	ft_one(t);
	return (ft_sniff(t));
}

void	ft_tbfix(t_t *t)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < t->maxy)
	{
		while (t->tb[y][x] != '\0')
		{
			if (t->tb[y][x] == ' ')
				t->tb[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_tb_fill(t_t *t)
{
	int i;
	int ib;
	int y;

	i = 0;
	y = 0;
	ib = 0;
	while (t->map[i] != '\0' && y < t->maxy)
	{
		if (t->demimap == t->maxy && t->map[i] == ' ')
			i++;
		t->tb[y][ib] = t->map[i];
		ib++;
		i++;
		if (t->map[i] == '\n')
		{
			t->tb[y][ib] = '\0';
			ib = 0;
			i++;
			y++;
		}
	}
}

void	ft_tb_made(t_t *t)
{
	int i;
	int y;

	i = 0;
	while (t->map[i] != '\0')
	{
		(t->map[i] == '\n') ? t->maxy++ : 0;
		i++;
	}
	t->tb = malloc(sizeof(char *) * t->maxy + 1);
	i = 0;
	y = 0;
	while (t->map[i] != '\0' && t->o < t->maxy)
	{
		while (t->map[i] != '\n' && t->map[i] != '\0')
		{
			y++;
			i++;
		}
		(t->demimap == t->maxy) ? y = y / 2 : 0;
		t->tb[t->o] = malloc(sizeof(char) * y + 1);
		t->o++;
		y = 0;
		i++;
	}
}

void	ft_scoot(char *line, t_t *t)
{
	int		i;
	char	str[2];
	char	*leaks;

	str[0] = '\n';
	str[1] = '\0';
	i = 0;
	while (ft_white_space(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		ft_free_strjoin(t->map, line, &t->map);
		ft_free_strjoin(t->map, str, &t->map);
	}
}
