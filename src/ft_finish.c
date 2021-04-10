/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:38:56 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 16:35:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_skip(char *str, int i)
{
	if (!str || !str[i])
		return (0);
	while (str[i] != '\0' && ft_white_space(str[i]))
		i++;
	return (i);
}

char	*ft_recup_str(char *str, int i)
{
	int		y;
	char	*tmp;

	y = 0;
	while (ft_beta(str[i]))
		i++;
	i = ft_skip(str, i);
	tmp = NULL;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0' && str[i] != ' ')
	{
		tmp[y] = str[i];
		i++;
		y++;
	}
	while (y < ft_strlen(str) + 1)
		tmp[y++] = '\0';
	return (tmp);
}

void	ft_parse_nbr(t_t *t, char *line)
{
	int i;
	int val;

	i = ft_skip(line, 0);
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		i++;
		i = ft_skip(line, i);
		val = ft_atoi(line + i);
		t->ccolor = (val > 255 || val < 0) ? 255 : val;
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		val = ft_atoi(line + i++);
		t->ccolor = (t->ccolor << 8) + (val > 255 || val < 0) ? 255 : val;
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		val = ft_atoi(line + i++);
		t->ccolor = (t->ccolor << 8) + (val > 255 || val < 0) ? 255 : val;
	}
}

int		ft_sniff(t_t *t)
{
	if (t->error == 1)
		return (0);
	return (1);
}

void	ft_print_map(t_t *t)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < t->maxy)
	{
		while (t->tb[y][x] != '\0')
		{
			if (t->tb[y][x] == '0')
				t->tb[y][x] = '1';
			if (t->tb[y][x] == 'X')
				t->tb[y][x] = '0';
			if (t->tb[y][x] == 'x')
				t->tb[y][x] = '2';
			x++;
		}
		y++;
		x = 0;
	}
}
