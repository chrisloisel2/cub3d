/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:23:54 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/13 11:14:31 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_putkey(int c, t_t *t)
{
	double	vitesse;
	double	r;
	double	olddirx;
	double	oldplanex;

	olddirx = t->dirx;
	oldplanex = t->planex;
	r = 0.05;
	vitesse = 0.5;
	(c == 122 || c == 13 || c == 119) ? ft_avant(t, vitesse) : 0;
	(c == 100 || c == 2) ? ft_droite(t, vitesse) : 0;
	(c == 115 || c == 1) ? ft_arriere(t, vitesse) : 0;
	(c == 113 || c == 0 || c == 97) ? ft_gauche(t, vitesse) : 0;
	(c == 65363 || c == 124) ? ft_rot(t, r) : 0;
	(c == 65361 || c == 123) ? ft_rot(t, -r) : 0;
	t->casex = (int)t->x;
	t->casey = (int)t->y;
	if (c == 65307 || c == 53)
		exit(0);
	ft_screen(t);
	return (0);
}
