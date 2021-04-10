/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/13 17:18:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_startdda(t_t *t, int x)
{
	t->camerax = ((x / (double)t->win_x) * 2) - 1;
	t->rayx = t->dirx + (t->planex * t->camerax);
	t->rayy = t->diry + (t->planey * t->camerax);
	t->casey = (int)t->y;
	t->casex = (int)t->x;
	t->deltadistx = sqrt(1 + (t->rayy * t->rayy) / (t->rayx * t->rayx));
	t->deltadisty = sqrt(1 + (t->rayx * t->rayx) / (t->rayy * t->rayy));
	t->side = 0;
}

void		ft_setupdda(t_t *t, int x)
{
	ft_startdda(t, x);
	if (t->rayx < 0)
	{
		t->stepx = -1;
		t->sidedistx = (t->x - t->casex) * t->deltadistx;
	}
	else
	{
		t->stepx = 1;
		t->sidedistx = (t->casex + 1.0 - t->x) * t->deltadistx;
	}
	if (t->rayy < 0)
	{
		t->stepy = -1;
		t->sidedisty = (t->y - t->casey) * t->deltadisty;
	}
	else
	{
		t->stepy = 1;
		t->sidedisty = (t->casey + 1.0 - t->y) * t->deltadisty;
	}
}

void		ft_cheapdda(t_t *t, float lineheight, t_sprite *first)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (t->sidedistx < t->sidedisty)
		{
			t->sidedistx += t->deltadistx;
			t->casex += t->stepx;
			t->side = 0;
		}
		else
		{
			t->sidedisty += t->deltadisty;
			t->casey += t->stepy;
			t->side = 1;
		}
		(t->tb[t->casey][t->casex] == '1') ? hit = 1 : 0;
		if (t->tb[t->casey][t->casex] == '2')
			ft_sprite(t, first);
	}
	if (t->side == 0)
		t->perpwalldist = (t->casex - t->x + (1 - t->stepx) / 2) / t->rayx;
	else
		t->perpwalldist = (t->casey - t->y + (1 - t->stepy) / 2) / t->rayy;
}
