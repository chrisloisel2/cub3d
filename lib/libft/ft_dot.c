/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:59:48 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/17 03:49:36 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_dot(const char *s, va_list *ap, t_pft *one)
{
	one->dot = 1;
	one->index++;
	ft_get_all(s, ap, one);
	if (one->resultneg == 1)
	{
		if (ft_strlen(one->result) - one->resultneg < one->truepres1)
			one->pres1++;
		ft_cast_min(one);
	}
	if (one->flag != 0)
		ft_flag(one);
	if (one->point == 1)
		ft_putstr("0x", one);
	while (one->pres1-- > 0 && one->pres1neg == 0)
		ft_putchar('0', one);
	if (one->resaff == 0)
		ft_putstr(one->result + one->decal, one);
	free(one->result);
}
