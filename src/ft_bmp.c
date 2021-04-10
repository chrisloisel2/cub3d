/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:15:25 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/26 16:20:00 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_write_header(int fd, t_t *t)
{
	int tmp;

	write(fd, "BM", 2);
	tmp = 54 + 4 * t->win_x * t->win_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 4);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &t->win_x, 4);
	write(fd, &t->win_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	tmp = 32;
	write(fd, &tmp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

unsigned int	get_pixel(t_t *t, int x, int y)
{
	unsigned int *src;

	src = t->si + ((y * t->win_x) + x);
	return (*src);
}

void			ft_write_pixels(int fd, t_t *t)
{
	int				y;
	int				x;
	unsigned int	pixel;

	x = t->win_y;
	y = 0;
	while (x > 0)
	{
		y = 0;
		while (y < t->win_x)
		{
			pixel = get_pixel(t, y, x);
			write(fd, &pixel, 4);
			y++;
		}
		x--;
	}
}

int				ft_save(t_t *t)
{
	int fd;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC);
	if (fd < 0)
	{
		printf("screen shot err\n");
		close(fd);
		return (0);
	}
	else
	{
		ft_write_header(fd, t);
		ft_write_pixels(fd, t);
	}
	return (1);
}

void			ft_write_sprite(t_t *t, t_sprite *first, int stripe)
{
	int					y;
	int					x;
	int					d;
	float				hauteur;
	int					ygrek;

	y = first->drawstarty;
	x = (double)(stripe / first->valek) * t->tl[4];
	first->texx = (int)(256 * (stripe - (-first->spritewidth / 2 +
		first->screenx)) * t->tl[4] / first->spritewidth) / 256;
	if (first->transformy > 0 && stripe > 0 && stripe < t->win_x)
		while (y < first->drawendy)
		{
			d = (y * 256) - (t->win_y * 128) + (first->spriteheight * 128);
			first->texy = (d * t->th[4]) / first->spriteheight / 256;
			hauteur = first->drawendy - first->drawstarty;
			ygrek = (double)((y - first->drawstarty) / hauteur) * t->th[4];
			if ((t->tl[4] * first->texy + first->texx) < (t->tl[4] *
				t->th[4]) && (t->tl[4] * first->texy + first->texx) > 0)
				first->color = t->tx[4][t->tl[4] * first->texy + first->texx];
			if ((first->color & 0x00FFFFFF) != 0 &&
					(first->transformy - 1) < t->w[stripe])
				t->si[(long)(y * t->win_x) + (int)stripe] = first->color;
			y++;
		}
}
