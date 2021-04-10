/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 16:31:30 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_recup_sprite(t_t *t)
{
	int i;
	int un;

	t->tx[4] =
	(unsigned int *)mlx_get_data_addr(t->ptrs, &t->ns, &t->sl, &un);
}

void	ft_recuperation(t_t *t)
{
	int	i;
	int un;
	int deux;
	int trois;
	int quatre;

	trois = 0;
	quatre = 0;
	t->tx[0] =
	(unsigned int *)mlx_get_data_addr(t->ptrno, &t->nno, &t->nosl, &un);
	t->tx[1] =
	(unsigned int *)mlx_get_data_addr(t->ptrea, &t->nea, &t->easl, &deux);
	t->tx[2] =
	(unsigned int *)mlx_get_data_addr(t->ptrwe, &t->nwe, &t->wesl, &trois);
	t->tx[3] =
	(unsigned int *)mlx_get_data_addr(t->ptrso, &t->nso, &t->sosl, &quatre);
}

void	ft_recup(t_t *t)
{
	t->tx = malloc(sizeof(unsigned int *) * 5);
	t->tl = malloc(sizeof(int) * 5);
	t->th = malloc(sizeof(int) * 5);
	t->ptrno = mlx_xpm_file_to_image(t->mlx_ptr, t->no, &t->tl[0], &t->th[0]);
	t->ptrea = mlx_xpm_file_to_image(t->mlx_ptr, t->ea, &t->tl[1], &t->th[1]);
	t->ptrwe = mlx_xpm_file_to_image(t->mlx_ptr, t->we, &t->tl[2], &t->th[2]);
	t->ptrso = mlx_xpm_file_to_image(t->mlx_ptr, t->so, &t->tl[3], &t->th[3]);
	t->ptrs = mlx_xpm_file_to_image(t->mlx_ptr, t->s, &t->tl[4], &t->th[4]);
	if (!(t->ptrs && t->ptrso && t->ptrwe && t->ptrea && t->ptrno))
	{
		t->error = 1;
		return ;
	}
	ft_recuperation(t);
	ft_recup_sprite(t);
}

void	ft_lst_params(t_sprite *first)
{
	first->invdet = 0;
	first->spritex = 0;
	first->spritey = 0;
	first->nb = 0;
	first->x = 0;
	first->y = 0;
	first->dist = 0;
	first->transformx = 0;
	first->transformy = 0;
	first->spritescreenx = 0;
	first->spriteheight = 0;
	first->drawstarty = 0;
	first->drawendy = 0;
	first->spritewidth = 0;
	first->drawstartx = 0;
	first->drawendx = 0;
	first->next = NULL;
	first->prev = NULL;
}
