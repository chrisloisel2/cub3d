/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 03:04:05 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 01:12:15 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_puthexa(unsigned int nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_get_puthexa(nb / 16, one);
	}
	ft_get_putchar(base_data[nb % 16], one);
	one->display = 'x';
}

void	ft_get_puthexa_maj(unsigned int nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_get_puthexa_maj(nb / 16, one);
	}
	ft_get_putchar(base_data[nb % 16], one);
	one->display = 'X';
}

void	ft_get_putu(unsigned int nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789";
	if (nb >= 10)
	{
		ft_get_putu(nb / 10, one);
	}
	ft_get_putchar(base_data[nb % 10], one);
	one->display = 'u';
}

void	ft_get_putnbr(int nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789";
	if (nb == -2147483648)
	{
		one->resultneg = 1;
		ft_get_putstr("-2147483648", one);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			one->resultneg = 1;
			ft_get_putchar('-', one);
		}
		if (nb >= 10)
		{
			ft_get_putnbr(nb / 10, one);
		}
		ft_get_putchar(base_data[nb % 10], one);
	}
	one->display = 'd';
}
