/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 02:00:33 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/19 19:13:34 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct			s_pft
{
	int		cpt;
	int		index;
	int		pres1;
	int		truepres1;
	int		truepres2;
	int		star;
	int		dot;
	int		minus;
	int		decal;
	int		p1;
	int		p2;
	int		zero;
	int		point;
	int		pres1neg;
	int		pres2;
	int		pres2neg;
	int		resultneg;
	int		resaff;
	int		null;
	char	*result;
	char	flag;
	char	display;

}						t_pft;

int						ft_intlen(long c);
int						ft_printf(const char *s, ...);
void					ft_var(const char *s, va_list *ap, t_pft *one);
void					ft_putchar(char c, t_pft *one);
void					ft_putstr(char *s, t_pft *one);
void					ft_putnbr(int nb, t_pft *one);
void					ft_putu(unsigned int nb, t_pft *one);
void					ft_puthexa_maj(long long nb, t_pft *one);
void					ft_puthexa(long long nb, t_pft *one);
void					ft_point(unsigned long p, t_pft *one);
int						ft_atoi(const char *str);
void					ft_get_pres1(const char *s, va_list *ap, t_pft *one);
void					ft_get_pres2(const char *s, va_list *ap, t_pft *one);
void					ft_get_flag(const char *s, t_pft *one);
void					ft_get_var(const char *s, va_list *ap, t_pft *one);
void					ft_star(const char *s, va_list *ap, t_pft *one);
void					ft_get_putnbr(int nb, t_pft *one);
void					ft_get_puthexa(unsigned int nb, t_pft *one);
void					ft_get_putu(unsigned int nb, t_pft *one);
void					ft_get_puthexa_maj(unsigned int nb, t_pft *one);
void					ft_get_putstr(char *s, t_pft *one);
void					ft_get_putchar(char c, t_pft *one);
void					ft_get_point(unsigned long p, t_pft *one);
void					ft_free_strjoin(char *s1, char *s2, char **leaks);
void					ft_get_all(const char *s, va_list *ap, t_pft *one);
void					ft_calculus(t_pft *one);
void					ft_dot(const char *s, va_list *ap, t_pft *one);
int						ft_alpha(char c);
void					ft_minus(const char *s, va_list *ap, t_pft *one);
void					ft_zero(const char *s, va_list *ap, t_pft *one);
void					ft_flag(t_pft *one);
void					ft_zerosuppr(t_pft *one);
int						ft_zerocal(t_pft *one);
void					ft_cast_min(t_pft *one);
void					ft_cast(t_pft *one);
void					ft_fixstr(t_pft *one);
int						ft_checkflag(char c);
void					ft_errors(const char *s, t_pft *one);
int						ft_checkdisplay(char c);
void					ft_point_long(unsigned long nb, t_pft *one);
void					ft_minus_flag(t_pft *one);

#endif
