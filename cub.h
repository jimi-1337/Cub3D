/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:53:12 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 18:54:03 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define BUFFER_SIZE 1

typedef struct	s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*data;
	int				*data_texn;
	int				*data_texs;
	int				*data_texe;
	int				*data_texw;
	int				*data_sprite;
	void			*img_texn;
	void			*img_texs;
	void			*img_texe;
	void			*img_texw;
	void			*img_ptr;
	void			*img_sprite;
	int				bpp;
	int				endian;
	int				line;
}				t_win;

typedef struct	s_vect
{
	float			x;
	float			y;
}				t_vect;

typedef struct	s_intvect
{
	int				x;
	int				y;
}				t_intvect;

typedef struct	s_draw
{
	int				wlineheight;
	int				wdrawstart;
	int				wdrawend;
	int				wcolor;
	int				wtexx;
	int				wtexy;
	float			wallx;
	float			spritex;
	float			spritey;
	float			transformx;
	float			transformy;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				spritescreen;
	int				spriteheight;
	int				spritewidth;
}				t_draw;

typedef struct	s_player
{
	t_vect			pos;
	t_vect			dir;
	t_vect			plane;
	t_vect			raydir;
	t_vect			sidedist;
	t_vect			deltadist;
	t_vect			*sprite;
	float			camerax;
	float			perpwalldist;
	int				hit;
	int				side;
	int				nbr_sprite;
	t_intvect		step;
	t_intvect		map;
	t_win			win;
	t_draw			d;
	int				*spriteorder;
	float			*spritedistance;
	int				w;
	int				h;
	int				mapwidth;
	int				mapheight;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f_color;
	int				c_color;
	char			**world_map;
	char			*world;
	int				erreur;
	float			*zbuff;
}				t_player;

int				ft_isdigit(int c);
int				ft_atoi(const char *s);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_world_map(t_player *p, char *line);
int				ft_screen(t_player *p, char **tab);
int				ft_texture(t_player *p, char **tab);
int				ft_tsprite(t_player *p, char **tab);
int				ft_sol_plafond(t_player *p, char **tab);
int				fonct(char *line, t_player *p);
t_player		read_from_file(int fd, t_player p);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
int				ft_chr(const char *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_return(char **ch, int n, int fd, char **line);
int				get_next_line(int fd, char **line);
int				keys(int key, t_player *p);
t_player		pos_sprite(t_player p);
t_player		sort_sprite(t_player p);
t_player		draw(t_player p, int ac, char **av);
int				check_game(t_player *p);
char			*ft(char *tab);
int				nbr_ch(char **s);
int				ft_cmpr(char *s, char *t);
int				rgb(int r, int g, int b);
t_player		init_player(t_player *p);
int				create_bitmap(t_player *p, char *name);
t_player		draw_wall(t_player p);
t_player		draw_sprite(t_player p);
t_player		free_game(t_player p);
t_player		init_mlx(t_player p, int nb);
void			msg_erreur(t_player p);
t_player		check_positon(t_player p);
int				ft_world_map(t_player *p, char *line);
int				ft_sol_plafond(t_player *p, char **tab);
int				ft_texture(t_player *p, char **tab);
int				ft_screen(t_player *p, char **tab);
char			*split_space(char *tab);
int				worldmap(t_player *p, char **t);
void			ft_exit(void);
void			ft_putstr(char *s);
int				ft_check_r(char **tab);

#endif
