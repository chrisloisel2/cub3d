/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 07:49:36 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display(t_t *t)
{
	int	x;
	int y;
	int huit;
	int un;
	int sl;

	un = 1;
	huit = 3;
	sl = t->win_x;
	mlx_get_screen_size(t->mlx_ptr, &x, &y);
	if (t->win_x > x)
		t->win_x = x;
	if (t->win_y > y)
		t->win_y = y;
	t->image = mlx_new_image(t->mlx_ptr, t->win_x, t->win_y);
	t->si = (unsigned int *)mlx_get_data_addr(t->image, &huit, &sl, &un);
	if (!t->save)
	{
		t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "cub3D");
	}
}

int		ft_exit(t_t *t)
{
	exit(0);
	return (0);
}

int		ft_refresh(t_t *t)
{
	if (!t->save)
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
	return (1);
}

void	ft_start(t_t *t)
{
	t->mlx_ptr = mlx_init();
	ft_display(t);
	ft_recup(t);
	if (t->error)
	{
		printf("error sprite\n");
		return ;
	}
	ft_screen(t);
	(!t->save) ? mlx_hook(t->mlx_win, 15, (1L << 16), ft_refresh, t) : 0;
	(!t->save) ? mlx_hook(t->mlx_win, 2, (1L << 0), &ft_putkey, t) : 0;
	(!t->save) ? mlx_hook(t->mlx_win, 33, (0), ft_exit, t) : 0;
	(!t->save) ? mlx_hook(t->mlx_win, 3, (1L << 0), &ft_putkey, t) : 0;
	(!t->save) ? mlx_loop(t->mlx_ptr) : 0;
}

int		main(int argc, char **argv)
{
	t_t			t;
	int			fd;
	char		*str;

	t.save = 0;
	t.error = 0;
	fd = 0;
	ft_init(&t);
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_printf("error map");
	if (argc == 3 && ft_secure(argv[1]) && ft_parse(fd, &t) == 0 &&
		ft_check_arg(argv[2], &t))
	{
		ft_start(&t);
	}
	else if (argc == 2 && ft_secure(argv[1]) && ft_parse(fd, &t) == 0)
		ft_start(&t);
	else
		ft_printf("error arg");
	return (EXIT_SUCCESS);
}
