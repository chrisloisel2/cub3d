/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 03:43:53 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 02:13:02 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_putstr(char *s, t_pft *one)
{
	int i;

	i = 0;
	if (s == NULL)
		ft_get_putstr("(null)", one);
	else
	{
		while (s[i] != '\0')
		{
			ft_get_putchar(s[i], one);
			i++;
		}
	}
	one->display = 's';
}

void	ft_get_putchar(char c, t_pft *one)
{
	char	string[2];

	if (c == 0)
		one->null = 1;
	string[0] = c;
	string[1] = '\0';
	ft_free_strjoin(one->result, (char *)string, &one->result);
	one->display = 'c';
}

void	ft_get_point(unsigned long p, t_pft *one)
{
	if (one->truepres2 < one->truepres1 && one->dot == 0)
		ft_get_putstr("0x", one);
	else
		one->point = 1;
	ft_point_long(p, one);
	one->display = 'p';
}

void	ft_point_long(unsigned long nb, t_pft *one)
{
	char	*base_data;

	base_data = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_point_long(nb / 16, one);
	}
	ft_get_putchar(base_data[nb % 16], one);
}
