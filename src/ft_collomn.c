/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/20 14:54:33 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_trk_finish(t_t *t, int i)
{
	if (t->tb[t->fy][t->fx] == '0' && (t->fx == 0 || t->fy == 0))
		t->error = 1;
	if (t->tb[t->fy][t->fx] == '0' &&
			(t->fy == t->maxy - 1 || t->fx == t->maxx - 1))
		t->error = 1;
	t->trk[i][0] = t->fy;
	t->trk[i][1] = t->fx;
	t->trk[i][2] = ft_track_scan(t, t->fy, t->fx, i);
	t->trk[i][3] = 0;
	return (i + 1);
}

int		ft_check_arg(char *str, t_t *t)
{
	if (str[0] == '-' && str[1] == '-' && str[2] == 's')
		if (str[3] == 'a' && str[4] == 'v' && str[5] == 'e')
		{
			t->save = 1;
			return (1);
		}
	return (0);
}

void	ft_setuptrack(t_t *t)
{
	int i;

	i = 0;
	t->trk = malloc(sizeof(char *) * (t->maxy * (t->maxx + 1)));
	while (i < (t->maxx * t->maxy))
	{
		t->trk[i] = malloc(sizeof(char) * 4);
		t->trk[i][0] = 'x';
		t->trk[i][1] = 'x';
		t->trk[i][2] = 'x';
		t->trk[i][3] = 'x';
		i++;
	}
	t->fy = t->y;
	t->fx = t->x;
	t->tb[(int)t->y][(int)t->x] = 'X';
	t->trk[0][0] = t->fy;
	t->trk[0][1] = t->fx;
	t->trk[0][2] = ft_track_scan(t, t->fy, t->fx, i);
	t->trk[0][3] = 0;
}

void	ft_showmap(t_t *t)
{
	int i;

	i = 0;
	while (i < t->maxy)
	{
		printf("%s\n", t->tb[i]);
		i++;
	}
	printf("\n");
}

int		ft_secure(char *str)
{
	int i;

	i = ft_strlen(str) - 4;
	if (i < 3)
		i = 0;
	if (str[i + 0] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b')
		return (1);
	return (0);
}
