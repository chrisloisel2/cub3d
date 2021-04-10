/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:38:56 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 16:35:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sprite_setup(t_t *t, t_sprite *first)
{
	first->dist = ((t->x - first->x) * (t->x - first->x) +
	(t->y - first->y) * (t->y - first->y));
	first->x = t->casex + 0.5;
	first->y = t->casey + 0.5;
	first->spritex = first->x - t->x + 0.5;
	first->spritey = first->y - t->y + 0.5;
	first->invdet = 1.0 / (t->planex * t->diry - t->dirx * t->planey);
	first->transformx = first->invdet *
	(t->diry * first->spritex - t->dirx * first->spritey);
	first->transformy = first->invdet *
	(-t->planey * first->spritex + t->planex * first->spritey);
	first->spritescreenx = (int)((t->win_x / 2) *
	(1 + first->transformx / first->transformy));
	first->spriteheight = abs((int)(t->win_y / (first->transformy)));
	first->drawstarty = -first->spriteheight / 2 + t->win_y / 2;
	(first->drawstarty < 0) ? first->drawstarty = 0 : 0;
	first->drawendy = first->spriteheight / 2 + t->win_y / 2;
	(first->drawendy >= t->win_y) ? first->drawendy = t->win_y : 0;
	first->spritewidth = abs((int)(t->win_y / (first->transformy)));
	first->drawstartx = -first->spritewidth / 2 + first->spritescreenx;
	(first->drawstartx < 0) ? first->drawstartx = 0 : 0;
	first->drawendx = first->spritewidth / 2 + first->spritescreenx;
	(first->drawendx >= t->win_x) ? first->drawendx = t->win_x : 0;
}

int			ft_diff_sprite(t_t *t, t_sprite *first)
{
	first = ft_lst_first(first);
	while (first != NULL)
	{
		if (first->x == t->casex && first->y == t->casey)
			return (0);
		first = first->next;
	}
	return (1);
}

void		ft_sprite(t_t *t, t_sprite *first)
{
	if (ft_diff_sprite(t, first))
	{
		if (first->x != -1 && first->y != -1)
			first = ft_select_sprite(first);
		ft_sprite_setup(t, first);
	}
}

void		ft_clear_sprite(t_sprite *first)
{
	t_sprite	*new;
	int			alarme;

	alarme = 0;
	if (first->prev != NULL)
	{
		new = first->prev;
		new->next = NULL;
		alarme = 1;
	}
	free(first);
	first = NULL;
}

t_sprite	*ft_putsprite(t_t *t, t_sprite *first)
{
	t_sprite			*dot;
	double				stripe;

	dot = first->prev;
	first->valek = (first->drawendx + first->drawstartx);
	stripe = first->drawstartx;
	first->screenx = (int)((t->win_x / 2) *
	(1 + first->transformx / first->transformy));
	while (stripe < first->drawendx)
	{
		ft_write_sprite(t, first, stripe);
		stripe++;
	}
	ft_clear_sprite(first);
	return (dot);
}
