# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 14:54:40 by amoujane          #+#    #+#              #
#    Updated: 2020/02/21 16:02:53 by amoujane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = draw/draw.c get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c keys.c\
	   world_game/read_map.c sprite.c utils.c\
	   world_game/check_map.c main.c world_game/utils1.c\
	   init_player.c screen.c draw/draw_wall.c\
	   draw/draw_sprite.c initGame/init_mlx.c initGame/check_position.c\
	   world_game/read_map_utils.c ft_split.c

OBJ = draw/draw.o get_next_line/get_next_line.o\
	  get_next_line/get_next_line_utils.o keys.o\
	  world_game/read_map.o sprite.o utils.o\
	  world_game/check_map.o main.o world_game/utils1.o\
	  init_player.o screen.o draw/draw_wall.o\
	  draw/draw_sprite.o initGame/init_mlx.o initGame/check_position.o\
	  world_game/read_map_utils.o ft_split.o

HEADER = cub.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

MLX = -lmlx -framework OpenGL -framework AppKit -lz mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

norm:
	norminette $(SRCS) $(HEADER)

fclean: clean
	@rm -f $(NAME)

re: fclean all
