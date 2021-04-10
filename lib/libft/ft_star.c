/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 00:28:25 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/16 15:59:26 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_star(const char *s, va_list *ap, t_pft *one)
{
	one->star = 1;
	ft_get_all(s, ap, one);
	if (one->pres1neg == 0)
	{
		while (one->pres1-- > 0)
			ft_putchar(' ', one);
		if (one->flag != 0)
			ft_flag(one);
		if (one->resaff == 0)
			ft_putstr(one->result + one->decal, one);
	}
	else
	{
		if (one->flag != 0)
			ft_flag(one);
		if (one->resaff == 0)
			ft_putstr(one->result + one->decal, one);
		while (one->pres1-- > 0)
			ft_putchar(' ', one);
	}
	free(one->result);
}
