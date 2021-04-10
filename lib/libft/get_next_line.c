/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:20:52 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/07 02:25:32 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		ft_checkfile(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_run_stat(char *stat)
{
	char *leak;

	leak = stat;
	stat = ft_sub_str(stat, ft_checkfile(stat) + 1, ft_strlen(stat));
	free(leak);
	return (stat);
}

char	*ft_malloc(char **stat)
{
	*stat = malloc(sizeof(char) * 1);
	*stat[0] = '\0';
	return (*stat);
}

int		ft_return(char **stat, char ***line, int ret)
{
	if (ret > 0)
	{
		**line = ft_sub_str(*stat, 0, ft_checkfile(*stat));
		*stat = ft_run_stat(*stat);
		return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		tmp[BUFFER_SIZE + 1];
	static char	*stat;
	int			ret;
	char		*leak;

	ret = 0;
	(!stat) ? stat = ft_malloc(&stat) : 0;
	if (ft_checkfile(stat) != -1)
	{
		*line = ft_sub_str(stat, 0, ft_checkfile(stat));
		stat = ft_run_stat(stat);
		return (1);
	}
	while ((ft_checkfile(stat) == -1) && (ret = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		leak = stat;
		stat = ft_strjoin(stat, tmp);
		free(leak);
	}
	if ((ret = ft_return(&stat, &line, ret)) != 0)
		return (ret);
	*line = ft_sub_str(stat, 0, ft_strlen(stat));
	ft_freenull(&stat);
	return (0);
}
