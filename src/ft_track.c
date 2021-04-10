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

int		ft_tk(t_t *t, int i, int y, int x)
{
	float	test;
	int		index;

	index = 0;
	if (i > 1 && y == t->trk[0][0] && x == t->trk[0][1])
		return (1);
	while (t->trk[index][3] != 'x' && index < (t->maxx * t->maxy) - 1)
	{
		if (y == t->trk[index][0] && x == t->trk[index][1])
			return (0);
		index++;
	}
	return (1);
}

int		ft_track_scan(t_t *t, int y, int x, int i)
{
	int p;

	p = 0;
	if (y + 1 < t->maxy && (t->tb[y + 1][x] == '0' || t->tb[y + 1][x] == '2')
		&& ft_tk(t, i, y + 1, x))
		p++;
	if (x + 1 < t->maxx && (t->tb[y][x + 1] == '0' || t->tb[y][x + 1] == '2')
		&& ft_tk(t, i, y, x + 1))
		p++;
	if (y > 0 && (t->tb[y - 1][x] == '0' || t->tb[y - 1][x] == '2')
		&& ft_tk(t, i, y - 1, x))
		p++;
	if (x > 0 && (t->tb[y][x - 1] == '0' || t->tb[y][x - 1] == '2')
		&& ft_tk(t, i, y, x - 1))
		p++;
	return (p);
}

int		ft_tk_move(t_t *t, int i, int x, int y)
{
	if ((t->tb[y][x] == 'X' || t->tb[y][x] == 'x') &&
	(x == 0 || y == 0 || y == t->maxy - 1 || x == t->maxx - 1))
		t->error = 1;
	if (y + 1 < t->maxy && (t->tb[y + 1][x] == '0' || t->tb[y + 1][x] == '2')
		&& ft_tk(t, i, y + 1, x))
	{
		t->fy++;
		return (1);
	}
	if (x + 1 < t->maxx && (t->tb[y][x + 1] == '0' || t->tb[y][x + 1] == '2')
		&& ft_tk(t, i, y, x + 1))
	{
		t->fx++;
		return (1);
	}
	if (ft_look(t, i, x, y))
		return (1);
	return (0);
}

int		ft_track_control(t_t *t, int i)
{
	if (i == 1)
		return (1);
	if (t->error == 1)
		return (0);
	if (t->trk[i - 1][2] == 0)
	{
		i--;
		while (i >= 0)
		{
			if (t->trk[i][2] >= 1)
				t->trk[i][2] = ft_track_scan(t, t->trk[i][0], t->trk[i][1], i);
			if (t->trk[i][2] >= 1)
				break ;
			i--;
		}
	}
	if (i == -1)
		return (0);
	t->fx = t->trk[i][1];
	t->fy = t->trk[i][0];
	t->trk[i][2]--;
	return (1);
}

void	ft_one(t_t *t)
{
	int i;

	ft_setuptrack(t);
	i = 1;
	if (!(ft_track_scan(t, t->fy, t->fx, 0) == 0))
		while (ft_track_control(t, i))
			while (ft_tk_move(t, i, t->fx, t->fy))
			{
				i = ft_trk_finish(t, i);
				if (t->tb[t->fy][t->fx] == '0')
					t->tb[t->fy][t->fx] = 'X';
				if (t->tb[t->fy][t->fx] == '2')
					t->tb[t->fy][t->fx] = 'x';
			}
	ft_print_map(t);
}
