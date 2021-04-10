/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/17 14:34:28 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_text(t_t *t, char *line)
{
	int i;

	i = ft_skip(line, 0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		t->no = ft_recup_str(line, i);
	if (line[i] == 'S' && line[i + 1] == 'O')
		t->so = ft_recup_str(line, i);
	if (line[i] == 'W' && line[i + 1] == 'E')
		t->we = ft_recup_str(line, i);
	if (line[i] == 'E' && line[i + 1] == 'A')
		t->ea = ft_recup_str(line, i);
	if (line[i] == 'S' && line[i + 1] == ' ')
		t->s = ft_recup_str(line, i);
}

void	ft_parse_couleur(t_t *t, char *line)
{
	int i;
	int val;

	i = ft_skip(line, 0);
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		i++;
		i = ft_skip(line, i);
		val = ft_atoi(line + i);
		t->fcolor = (val > 255 || val < 0) ? 255 : val;
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		val = ft_atoi(line + i++);
		t->fcolor = (t->fcolor << 8) + val;
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		val = ft_atoi(line + i);
		t->fcolor = (t->fcolor << 8) + val;
	}
}

void	ft_parse_res(t_t *t, char *line)
{
	int i;

	i = ft_skip(line, 0);
	if (line[i] == 'R')
	{
		i++;
		i = ft_skip(line, i);
		t->win_x = ft_atoi(line + i);
		i += ft_intlen(t->win_x);
		i = ft_skip(line, i);
		t->win_y = ft_atoi(line + i);
	}
}

int		ft_check_error(t_t *t)
{
	int x;
	int y;

	if (!t->no || !t->so || !t->we || !t->ea || !t->s)
		t->error = 1;
	if (!t->tb || !t->map || t->win_x <= 0 || t->win_y <= 0)
		t->error = 1;
	if (t->fcolor < 0 || t->ccolor < 0)
		t->error = 1;
	if (t->fcolor > 0xFFFFFF || t->ccolor > 0xFFFFFF)
		t->error = 1;
	return (t->error);
}

int		ft_parse(int fd, t_t *t)
{
	int		i;
	char	*line;

	t->map = malloc(sizeof(char) * 1);
	t->map[0] = '\0';
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_parse_res(t, line);
		ft_parse_text(t, line);
		ft_parse_couleur(t, line);
		ft_parse_nbr(t, line);
		ft_scoot(line, t);
		free(line);
	}
	ft_scoot(line, t);
	free(line);
	ft_tb_made(t);
	if (t->win_x == 0 || t->win_y == 0 || t->ccolor == 0 || t->fcolor == 0
		|| t->map[0] == '\0' || t->maxy < 2)
		return (1);
	ft_tb_fill(t);
	ft_tbfix(t);
	ft_search_map(t);
	return (ft_check_error(t));
}
