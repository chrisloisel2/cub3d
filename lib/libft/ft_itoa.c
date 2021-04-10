/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 06:12:30 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/28 23:32:22 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cub(int n)
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

char	*ft_itoa(int n)
{
	char	*s;
	int		neg;
	int		i;
	int		len;
	long	nb;

	nb = (long)n;
	i = (n < 0) ? 1 : 0;
	neg = (n <= 0) ? -1 : 1;
	nb = (n < 0) ? nb * -1 : nb;
	len = ft_intlen(nb);
	if (!(s = malloc(sizeof(char) * (len + ((neg == -1) ? 2 : 1)))))
		return (0);
	s[0] = (neg == -1) ? '-' : '0';
	(n == 0) ? s[i++] = '0' : 0;
	while (len > 0)
	{
		len--;
		s[i] = (nb / ft_cub(len)) + 48;
		nb = nb % ft_cub(len);
		i++;
	}
	s[i] = '\0';
	return (s);
}
