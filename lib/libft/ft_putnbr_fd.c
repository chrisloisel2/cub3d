/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:07 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/28 19:14:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cube(int n)
{
	int c;

	c = 1;
	while (n > 0)
	{
		c = c * 10;
		n--;
	}
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	long	nb;

	nb = (long)n;
	len = (nb < 0) ? ft_intlen(-nb) : ft_intlen(nb);
	(nb < 0) ? ft_putchar_fd('-', fd) : 0;
	nb = (nb < 0) ? -nb : nb;
	(nb == 0) ? ft_putchar_fd('0', fd) : 0;
	while (len > 0)
	{
		len--;
		ft_putchar_fd((nb / ft_cube(len)) + 48, fd);
		nb = nb % ft_cube(len);
	}
}
