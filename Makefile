# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:59:06 by lchristo          #+#    #+#              #
#    Updated: 2021/03/14 20:35:35 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

LIB		=	libft.a

H		=	cub3d.h

SRC		=	main\
			ft_parsing\
			ft_init\
			ft_scoot\
			ft_maps\
			ft_screen\
			ft_collomn\
			ft_keys\
			ft_texture\
			ft_move\
			ft_dda\
			ft_sprite\
			ft_list\
			ft_recup\
			ft_bmp\
			ft_finish\
			ft_track

O		=	$(addprefix src/, $(addsuffix .o, $(SRC)))

C		=	$(addprefix src/, $(addsuffix .c, $(SRC)))

I		=	-I .\
			-I lib/libft\
			-I lib/minilibx-linux\
			-I /usr/local/include

CC		=	cc
# -Wall -Wextra -Werror

MLXFLAGS = -lm -lbsd -lX11 -lXext

%.o: %.c $H
	$(CC) $I -c $< -o $@

MLX = minilibx

all:
	@echo -n "\n\033[0;34mCompiling libft :\n"
	@$(MAKE) -C lib/libft
	@echo -n "\n\033[1;32mlibft done\n"
	@echo -n "compilation libft completed\n"
	@echo -n "\n"
	@echo -n "\n\033[0;34mCompiling...\n"
	@$(MAKE) -C lib/minilibx-linux
	@echo -n "\n\033[1;32mminilibx done\n"
	@echo -n "\033[0;34\n"
	@make $(NAME)

$(NAME): $O $H lib/libft/libft.a
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -o $@ $O lib/libft/libft.a lib/minilibx-linux/libmlx.a $(MLXFLAGS) -o $(NAME)
	@echo -n "\n\033[1;32mCUB3D generated\n\n"

debug: $O $H lib/libft/libft.a
	@echo -n "\n\033[0;34mCompiling libft :\n"
	@$(MAKE) -C lib/libft
	@echo -n "\n\033[1;32mlibft done\n"
	@echo -n "compilation libft completed\n"
	@echo -n "\n"
	@echo -n "\n\033[0;34mCompiling...\n"
	@$(MAKE) -C lib/minilibx-linux
	@echo -n "\n\033[1;32mminilibx done\n"
	@echo -n "\033[0;34\n"
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -g3 --sanitize=address -o $@ $C $I lib/libft/libft.a lib/minilibx-linux/libmlx.a $(MLXFLAGS) -o $(NAME)
	@echo -n "\n\033[1;32mCUB3D generated\n\n"

clean:
	rm -rf $O
	@$(MAKE) -C lib/minilibx-linux clean
	@$(MAKE) -C lib/libft clean

fclean: clean
	/bin/rm -f $(NAME) screenshot.bmp

re:
	@echo -n "\n\033[0;34mCompiling...\n"
	cc -o $@ $O lib/libft/libft.a lib/minilibx-linux/libmlx.a $(MLXFLAGS) -o $(NAME)
	@echo -n "\n\033[1;32mCUB3D generated\n\n"
