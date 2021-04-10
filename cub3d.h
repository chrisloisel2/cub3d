/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:25:59 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:21:57 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>
# include "gnl.h"
# include "libft.h"
# include "printf.h"
# include "mlx.h"

typedef struct	s_sprite
{
	int						texx;
	int						texy;
	double					invdet;
	double					spritex;
	double					spritey;
	double					valek;
	int						screenx;
	int						nb;
	int						x;
	int						y;
	float					dist;
	double					transformx;
	double					transformy;
	int						spritescreenx;
	int						spriteheight;
	int						drawstarty;
	int						drawendy;
	unsigned int			color;
	int						spritewidth;
	int						drawstartx;
	int						drawendx;
	struct s_sprite			*prev;
	struct s_sprite			*next;
}				t_sprite;

typedef struct	s_t
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*image;
	float				*speed;
	int					error;
	int					*w;
	unsigned int		*si;
	int					demimap;
	double				x;
	double				y;
	double				camerax;
	double				cameray;
	int					casex;
	int					casey;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	float				mur_h;
	float				mur_w;
	float				disty;
	float				distx;
	int					*th;
	int					*tl;
	float				drawend;
	float				drawstart;
	float				cam_distance;
	char				**tb;
	char				*map;
	int					maxy;
	int					maxx;
	int					win_x;
	int					win_y;
	int					ccolor;
	int					fcolor;
	int					fx;
	int					o;
	int					fy;
	int					sprite;
	double				rayx;
	double				rayy;
	double				lineheight;
	double				rdirx;
	double				rdiry;
	int					stepx;
	int					stepy;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	double				sidedistx;
	double				sidedisty;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	void				*ptrno;
	void				*ptrs;
	void				*ptrso;
	void				*ptrwe;
	void				*ptrea;
	char				**trk;
	int					nol;
	int					sol;
	int					wel;
	int					eal;
	int					sl;
	int					save;
	int					noh;
	int					soh;
	int					weh;
	int					eah;
	int					sh;
	int					texx;
	int					texy;
	int					ns;
	int					nosl;
	int					sosl;
	int					wesl;
	int					easl;
	int					side;
	int					nno;
	int					nso;
	int					nwe;
	int					nea;
	float				texture_pos;
	float				plusbas;
	float				plushaut;
	unsigned int		*txtno;
	unsigned int		*txtso;
	unsigned int		*txtwe;
	unsigned int		*txtea;
	unsigned int		**tx;
	void				**tsprite;
}				t_t;

void			ft_screen(t_t *t);
void			ft_tbfix(t_t *t);
int				ft_check(char str);
int				ft_parse(int fd, t_t *t);
void			ft_putcolors(t_t *t);
void			ft_init(t_t *t);
void			ft_display(t_t *t);
void			ft_scoot(char *line, t_t *t);
void			ft_tb_made(t_t *t);
void			ft_tb_fill(t_t *t);
void			ft_two(t_t *t);
void			ft_one(t_t *t);
void			ft_perfect_cube(t_t *t);
int				ft_white_space(char c);
int				ft_search_map(t_t *t);
void			ft_map_check(t_t *t);
void			ft_collomn(t_t *t, int i);
void			ft_ceiling(t_t *t);
void			ft_floor(t_t *t);
int				ft_putkey(int c, t_t *t);
void			ft_print_map(t_t *t);
void			ft_pixel_texture(t_t *t, int y, t_sprite *first);
void			ft_putpixel(t_t *t, double hauteur, int i, double index);
void			ft_avant(t_t *t, double vitesse);
void			ft_arriere(t_t *t, double vitesse);
void			ft_droite(t_t *t, double vitesse);
void			ft_gauche(t_t *t, double vitesse);
void			ft_rot(t_t *t, double r);
void			ft_cheapdda(t_t *t, float lineheight, t_sprite	*first);
void			ft_setupdda(t_t *t, int x);
int				ft_get_player_two(char c, t_t *t);
t_sprite		*ft_putsprite(t_t *t, t_sprite *first);
void			ft_sprite(t_t *t, t_sprite *first);
t_sprite		*ft_select_sprite(t_sprite *first);
t_sprite		*ft_lst_new(void);
void			ft_lst_add_back(t_sprite **alst, t_sprite *new);
t_sprite		*ft_lst_last(t_sprite *lst);
t_sprite		*ft_lst_first(t_sprite *lst);
void			ft_t_spriteri(t_t *t, t_sprite *first);
void			ft_recup(t_t *t);
void			ft_lst_params(t_sprite *first);
int				ft_save(t_t *t);
void			ft_write_sprite(t_t *t, t_sprite *first, int stripe);
int				ft_skip(char *str, int i);
void			ft_parse_nbr(t_t *t, char *line);
char			*ft_recup_str(char *str, int i);
int				ft_beta(char c);
int				ft_sniff(t_t *t);
int				ft_trk_finish(t_t *t, int i);
int				ft_track_scan(t_t *t, int y, int x, int i);
int				ft_check_arg(char *str, t_t *t);
void			ft_setuptrack(t_t *t);
void			ft_showmap(t_t *t);
int				ft_secure(char *str);
int				ft_look(t_t *t, int i, int x, int y);
int				ft_tk(t_t *t, int i, int y, int x);

#endif
