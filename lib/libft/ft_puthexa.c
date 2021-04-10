/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:15:37 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 00:46:31 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthexa(long long nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789abcdef";
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', one);
	}
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, one);
	}
	ft_putchar(base_data[(nb % 16)], one);
}

void	ft_puthexa_maj(long long nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789ABCDEF";
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', one);
	}
	if (nb >= 16)
	{
		ft_puthexa_maj(nb / 16, one);
	}
	ft_putchar(base_data[(nb % 16)], one);
}

void	ft_putu(unsigned int nb, t_pft *one)
{
	if (nb >= 10)
	{
		ft_putu(nb / 10, one);
	}
	ft_putchar((nb % 10) + '0', one);
}

void	ft_putnbr(int nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789";
	if (nb == -2147483648)
	{
		one->resultneg = 1;
		ft_putstr("-2147483648", one);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-', one);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10, one);
		}
		ft_putchar(base_data[(nb % 10)], one);
	}
}
