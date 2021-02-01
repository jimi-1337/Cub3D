/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:51:46 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:53:00 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player	draw(t_player p, int ac, char **av)
{
	int i;

	i = 0;
	ft_bzero(p.win.data, p.w * p.h * 4);
	p = draw_wall(p);
	p = draw_sprite(p);
	if (ac == 3 && !ft_cmpr(av[2], "--save"))
	{
		create_bitmap(&p, "screen.bmp");
		p = free_game(p);
		exit(0);
	}
	else
		mlx_put_image_to_window(p.win.mlx_ptr,
			p.win.win_ptr, p.win.img_ptr, 0, 0);
	return (p);
}
