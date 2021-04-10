/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 02:06:43 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 01:18:20 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *s, t_pft *one)
{
	int i;

	i = 0;
	if (s == NULL)
		ft_putstr("(null)", one);
	else
	{
		while (s[i] != '\0' || one->null == 1)
		{
			if (one->null == 1)
				one->null = 0;
			ft_putchar(s[i], one);
			i++;
		}
	}
}

void	ft_putchar(char c, t_pft *one)
{
	write(1, &c, 1);
	one->cpt++;
}

void	ft_point(unsigned long p, t_pft *one)
{
	ft_putstr("0x", one);
	ft_puthexa(p, one);
}
