/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 02:08:25 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/19 19:13:24 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag(t_pft *one)
{
	if (one->flag == '.')
	{
		if (one->pres2neg == 0)
		{
			if (one->resultneg == 1 && one->resaff == 0)
				ft_cast_min(one);
			(one->point == 1) ? ft_putstr("0x", one) : 0;
			while (one->pres2-- > 0 && one->pres2neg == 0)
				ft_putchar('0', one);
		}
	}
	if (one->flag == '-')
		ft_minus_flag(one);
}

int		ft_checkflag(char c)
{
	if (c == '.')
		return (1);
	if (c == '0')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

int		ft_checkdisplay(char c)
{
	if (c == 'c')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

void	ft_minus_flag(t_pft *one)
{
	if (one->pres2neg == 0)
	{
		if (one->resultneg == 1 && one->resaff == 0)
		{
			ft_cast_min(one);
			one->pres2--;
		}
		ft_putstr(one->result + one->decal, one);
		one->resaff = 1;
		while (one->pres2-- > 0 && one->pres2neg == 0)
			ft_putchar(' ', one);
	}
}
