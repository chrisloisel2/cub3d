/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 16:26:31 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free(t_t *t, t_sprite *first)
{
	free(first);
	first = NULL;
}

void		ft_screenshot(t_t *t, t_sprite *first)
{
	int i;

	first = ft_lst_last(first);
	while (first != NULL)
		first = ft_putsprite(t, first);
	free(t->w);
	t->w = NULL;
	if (t->save)
	{
		ft_save(t);
		exit(0);
	}
	else
	{
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
	}
}

void		ft_screen(t_t *t)
{
	int				x;
	double			lineheight;
	t_sprite		*first;

	x = 0;
	first = ft_lst_new();
	t->w = malloc(sizeof(int) * t->win_x);
	(!t->save) ? mlx_clear_window(t->mlx_ptr, t->mlx_win) : 0;
	while (x < t->win_x)
	{
		ft_setupdda(t, x);
		ft_cheapdda(t, lineheight, ft_lst_last(first));
		(t->perpwalldist == 0) ? t->perpwalldist = 0.5 : 0;
		lineheight = (t->win_y / t->perpwalldist);
		t->w[x] = t->perpwalldist;
		t->lineheight = lineheight;
		t->drawstart = -lineheight / 2 + t->win_y / 2;
		(t->drawstart < 0) ? t->drawstart = 0 : 0;
		t->drawend = lineheight / 2 + t->win_y / 2;
		t->plushaut = lineheight / 2 + t->win_y / 2;
		(t->drawend >= t->win_y) ? t->drawend = t->win_y : 0;
		ft_pixel_texture(t, x, ft_lst_last(first));
		x++;
	}
	ft_screenshot(t, first);
}

int			ft_look(t_t *t, int i, int x, int y)
{
	if (y > 0 && (t->tb[y - 1][x] == '0' || t->tb[y - 1][x] == '2')
		&& ft_tk(t, i, y - 1, x))
	{
		t->fy--;
		return (1);
	}
	if (x > 0 && (t->tb[y][x - 1] == '0' || t->tb[y][x - 1] == '2')
		&& ft_tk(t, i, y, x - 1))
	{
		t->fx--;
		return (1);
	}
	return (0);
}
