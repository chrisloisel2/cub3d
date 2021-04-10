/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:20:23 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 01:42:31 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_minus(const char *s, va_list *ap, t_pft *one)
{
	one->minus = 1;
	one->index++;
	ft_get_all(s, ap, one);
	if (one->display == 's')
	{
		ft_putstr(one->result + one->decal, one);
		one->resaff = 1;
	}
	if (one->flag != 0)
		ft_flag(one);
	if (one->resaff == 0)
		ft_putstr(one->result + one->decal, one);
	while (one->pres1-- > 0)
		ft_putchar(' ', one);
	free(one->result);
}

void	ft_cast_min(t_pft *one)
{
	ft_putchar('-', one);
	one->decal = 1;
	one->resultneg = 0;
}

void	ft_fixstr(t_pft *one)
{
	int i;

	i = (one->flag != 0) ? one->pres2 : one->pres1;
	if (one->flag != 0 && one->pres2neg == 1)
		return ;
	if (one->flag == 0 && one->pres1neg == 1)
		return ;
	if (one->minus == 1 && one->flag == 0)
		return ;
	if (one->display == 's' && one->zero == 0)
	{
		if (one->flag == 0 && one->star == 1)
			return ;
		while (one->result[i] != '\0')
			one->result[i++] = '\0';
		if (one->flag != 0)
		{
			one->truepres2 = 0;
			one->pres2 = 0;
			one->p2 = 0;
		}
		else
			one->pres1 = 0;
	}
}
