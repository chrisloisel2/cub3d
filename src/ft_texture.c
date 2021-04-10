/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:14:15 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/27 09:40:59 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_side(t_t *t)
{
	if (t->side == 0)
	{
		if (t->rayx > 0)
			return (2);
		else
			return (1);
	}
	if (t->side == 1)
	{
		if (t->rayy > 0)
			return (3);
		else
			return (0);
	}
	return (1);
}

int		ft_diff_texture(t_t *t, int y, int x)
{
	unsigned int	color;
	double			step;
	double			texpos;

	step = 1.0 * t->th[ft_side(t)] / t->lineheight;
	texpos = (t->drawstart - (t->win_y / 2) + (t->lineheight / 2)) * step;
	while (y < t->drawend)
	{
		t->texy = (int)texpos;
		texpos += step;
		if (ft_side(t) >= 0 && t->texy >= 0)
			color = t->tx[ft_side(t)][(t->tl[ft_side(t)] * t->texy) + t->texx];
		if (t->side == 1)
			color = (color >> 1) & 8355711;
		t->si[(y * t->win_x) + x] = color;
		y++;
	}
	return (y);
}

void	ft_pixend(t_t *t, int y, int x)
{
	y = ft_diff_texture(t, y, x);
	while (y <= t->win_y)
	{
		t->si[(y * t->win_x) + x] = t->fcolor;
		y++;
	}
}

void	ft_pixel_texture(t_t *t, int y, t_sprite *first)
{
	int				value;
	int				x;
	int				tex;
	double			wallx;

	tex = ft_side(t);
	x = y;
	y = 0;
	if (t->side == 0)
		wallx = t->y + t->perpwalldist * t->rayy;
	else
		wallx = t->x + t->perpwalldist * t->rayx;
	wallx -= floor((wallx));
	t->texx = (int)(wallx * (double)(t->tl[tex]));
	(t->side == 0 && t->rayx > 0) ? t->texx = t->th[tex] - t->texx - 1 : 0;
	(t->side == 1 && t->rayy < 0) ? t->texx = t->th[tex] - t->texx - 1 : 0;
	while (y < t->drawstart)
	{
		value = (y * t->win_x) + x;
		if (value < (t->win_x * t->win_y) && value > 0)
			t->si[value] = t->ccolor;
		y++;
	}
	ft_pixend(t, y, x);
}
