/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:38:56 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/16 10:39:00 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_lst_first(t_sprite *lst)
{
	t_sprite	*t;

	t = lst;
	if (lst != NULL)
	{
		while (t->prev != NULL)
			t = t->prev;
	}
	return (t);
}

t_sprite	*ft_lst_last(t_sprite *lst)
{
	t_sprite	*t;

	t = lst;
	if (lst != NULL)
	{
		while (t->next != NULL)
			t = t->next;
	}
	return (t);
}

void		ft_lst_add_back(t_sprite **alst, t_sprite *new)
{
	t_sprite *p;

	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	p = (ft_lst_last(*alst));
	p->next = new;
	ft_lst_params(new);
	new->nb = p->nb + 1;
	new->prev = p;
}

t_sprite	*ft_select_sprite(t_sprite *first)
{
	t_sprite *new;

	new = malloc(sizeof(t_sprite));
	ft_lst_add_back(&first, new);
	return (ft_lst_last(first));
}

t_sprite	*ft_lst_new(void)
{
	t_sprite *first;

	if (!(first = malloc(sizeof(t_sprite))))
		return (NULL);
	ft_lst_params(first);
	first->y = -1;
	first->x = -1;
	return (first);
}
