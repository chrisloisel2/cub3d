/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 00:29:23 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/18 02:09:48 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_get_all(const char *s, va_list *ap, t_pft *one)
{
	one->result = malloc(sizeof(char) * 1);
	one->result[0] = '\0';
	ft_errors(s, one);
	ft_get_pres1(s, ap, one);
	ft_errors(s, one);
	ft_get_flag(s, one);
	ft_get_pres2(s, ap, one);
	ft_get_var(s, ap, one);
	ft_fixstr(one);
	ft_zerosuppr(one);
	ft_calculus(one);
	ft_errors(s, one);
}

void		ft_get_pres1(const char *s, va_list *ap, t_pft *one)
{
	if (s[one->index] == '0' && ft_alpha(s[one->index + 1]))
		one->index++;
	if (s[one->index] == '*')
	{
		one->pres1 = va_arg(*ap, int);
		one->index++;
	}
	else if (s[one->index] <= '9' && s[one->index] >= '0')
	{
		one->pres1 = ft_atoi(s + one->index);
		one->index = one->index + ft_intlen(one->pres1);
		one->index += (ft_intlen(one->pres1) == 0) ? 1 : 0;
	}
	else
		one->p1 = 0;
	one->truepres1 = one->pres1;
	if (one->pres1 < 0)
	{
		one->pres1neg = 1;
		one->pres1 *= -1;
	}
}

void		ft_get_pres2(const char *s, va_list *ap, t_pft *one)
{
	if (s[one->index] == '*')
	{
		one->pres2 = va_arg(*ap, int);
		one->index++;
	}
	else if (s[one->index] <= '9' && s[one->index] >= '0')
	{
		one->pres2 = ft_atoi(s + one->index);
		one->index = one->index + ft_intlen(one->pres2);
		one->index += (ft_intlen(one->pres2) == 0) ? 1 : 0;
	}
	else
		one->p2 = 0;
	one->truepres2 = one->pres2;
	if (one->pres2 < 0)
	{
		one->pres2neg = 1;
		one->pres2 *= -1;
	}
}

void		ft_get_flag(const char *s, t_pft *one)
{
	if (s[one->index] == '.')
	{
		one->flag = '.';
		one->index++;
	}
	else if (s[one->index] == '-')
	{
		one->flag = '-';
		one->index++;
	}
	else if (s[one->index] == '0')
	{
		one->flag = '0';
		one->index++;
	}
}

void		ft_get_var(const char *s, va_list *ap, t_pft *one)
{
	if (s[one->index] == 'x')
		ft_get_puthexa(va_arg(*ap, unsigned int), one);
	if (s[one->index] == 'X')
		ft_get_puthexa_maj(va_arg(*ap, unsigned int), one);
	if (s[one->index] == '%')
		ft_get_putstr("%", one);
	if (s[one->index] == 'p')
		ft_get_point(va_arg(*ap, unsigned long), one);
	if (s[one->index] == 'u')
		ft_get_putu(va_arg(*ap, unsigned long), one);
	if (s[one->index] == 'd')
		ft_get_putnbr(va_arg(*ap, int), one);
	if (s[one->index] == 'i')
		ft_get_putnbr(va_arg(*ap, int), one);
	if (s[one->index] == 's')
		ft_get_putstr(va_arg(*ap, char *), one);
	if (s[one->index] == 'c')
		ft_get_putchar(va_arg(*ap, int), one);
}
