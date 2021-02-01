/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:52:54 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:51:43 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player	ns_texture(t_player p, int a, int b)
{
	if (!(p.win.img_texn = mlx_png_file_to_image(p.win.mlx_ptr, p.no, &a, &b)))
	{
		p.erreur = -100;
		msg_erreur(p);
	}
	p.win.data_texn = (int *)mlx_get_data_addr(p.win.img_texn, &(p.win.bpp),
			&(p.win.line), &(p.win.endian));
	if (!(p.win.img_texs = mlx_png_file_to_image(p.win.mlx_ptr, p.so, &a, &b)))
	{
		p.erreur = -100;
		msg_erreur(p);
	}
	p.win.data_texs = (int *)mlx_get_data_addr(p.win.img_texs, &(p.win.bpp),
			&(p.win.line), &(p.win.endian));
	return (p);
}

t_player	ew_texture(t_player p, int a, int b)
{
	if (!(p.win.img_texe = mlx_png_file_to_image(p.win.mlx_ptr, p.ea, &a, &b)))
	{
		p.erreur = -100;
		msg_erreur(p);
	}
	p.win.data_texe = (int *)mlx_get_data_addr(p.win.img_texe, &(p.win.bpp),
			&(p.win.line), &(p.win.endian));
	if (!(p.win.img_texw = mlx_png_file_to_image(p.win.mlx_ptr, p.we, &a, &b)))
	{
		p.erreur = -100;
		msg_erreur(p);
	}
	p.win.data_texw = (int *)mlx_get_data_addr(p.win.img_texw, &(p.win.bpp),
			&(p.win.line), &(p.win.endian));
	return (p);
}

t_player	sprite(t_player p, int a, int b)
{
	if (!(p.win.img_sprite = mlx_png_file_to_image(p.win.mlx_ptr, p.s, &a, &b)))
	{
		p.erreur = -100;
		msg_erreur(p);
	}
	p.win.data_sprite = (int *)mlx_get_data_addr(p.win.img_sprite,
			&(p.win.bpp), &(p.win.line), &(p.win.endian));
	return (p);
}

t_player	init_mlx(t_player p, int nb)
{
	int a;
	int b;

	a = 64;
	b = 64;
	p = check_positon(p);
	p = pos_sprite(p);
	p.win.mlx_ptr = mlx_init();
	if (nb != 3)
		p.win.win_ptr = mlx_new_window(p.win.mlx_ptr, p.w, p.h, "Cub3D");
	p.win.img_ptr = mlx_new_image(p.win.mlx_ptr, p.w, p.h);
	p.win.data = (int *)mlx_get_data_addr(p.win.img_ptr, &(p.win.bpp),
			&(p.win.line), &(p.win.endian));
	p = ns_texture(p, a, b);
	p = ew_texture(p, a, b);
	p = sprite(p, a, b);
	return (p);
}
