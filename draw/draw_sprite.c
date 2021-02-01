/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:59:11 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:15 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player	ft_init_sprite(t_player p, int i)
{
	float invdet;

	p.d.spritex = p.sprite[p.spriteorder[i]].x - p.pos.x;
	p.d.spritey = p.sprite[p.spriteorder[i]].y - p.pos.y;
	invdet = 1.0 / (p.plane.x * p.dir.y - p.dir.x * p.plane.y);
	p.d.transformx = invdet * (p.dir.y * p.d.spritex - p.dir.x * p.d.spritey);
	p.d.transformy = invdet * ((-p.plane.y * p.d.spritex
				+ p.plane.x * p.d.spritey));
	p.d.spritescreen = (int)((p.w / 2) * (1 + p.d.transformx / p.d.transformy));
	p.d.spriteheight = abs((int)(p.h / (p.d.transformy)));
	p.d.drawstarty = -p.d.spriteheight / 2 + p.h / 2;
	if (p.d.drawstarty < 0)
		p.d.drawstarty = 0;
	p.d.drawendy = p.d.spriteheight / 2 + p.h / 2;
	if (p.d.drawendy >= p.h)
		p.d.drawendy = p.h - 1;
	p.d.spritewidth = abs((int)(p.h / (p.d.transformy)));
	p.d.drawstartx = -p.d.spritewidth / 2 + p.d.spritescreen;
	if (p.d.drawstartx < 0)
		p.d.drawstartx = 0;
	p.d.drawendx = p.d.spritewidth / 2 + p.d.spritescreen;
	if (p.d.drawendx >= p.w)
		p.d.drawendx = p.w - 1;
	return (p);
}

t_player	ft_sdraw(t_player p, int s, int d, int y)
{
	s = p.d.drawstartx;
	while (s < p.d.drawendx)
	{
		p.d.wtexx = (int)((s - (-p.d.spritewidth / 2 +
						p.d.spritescreen)) * TEX_WIDTH / p.d.spritewidth);
		if (p.d.transformy > 0 && s > 0 && s < p.w &&
				p.d.transformy < p.zbuff[s])
		{
			y = p.d.drawstarty;
			while (y < p.d.drawendy)
			{
				d = (y) - p.h / 2 + p.d.spriteheight / 2;
				p.d.wtexy = ((d * TEX_HEIGHT) / p.d.spriteheight);
				p.d.wcolor = p.win.data_sprite[TEX_WIDTH * p.d.wtexy
					+ p.d.wtexx];
				if ((p.d.wcolor & 0x00FFFFFF) != 0)
					p.win.data[p.w * y + s] = p.d.wcolor;
				y++;
			}
		}
		s++;
	}
	return (p);
}

t_player	draw_sprite(t_player p)
{
	int i;
	int s;
	int d;
	int y;

	i = -1;
	s = 0;
	d = 0;
	y = 0;
	while (++i < p.nbr_sprite)
	{
		p.spriteorder[i] = i;
		p.spritedistance[i] = ((p.pos.x - p.sprite[i].x) *
				(p.pos.x - p.sprite[i].x) + (p.pos.y - p.sprite[i].y)
				* (p.pos.y - p.sprite[i].y));
	}
	p = sort_sprite(p);
	i = 0;
	while (i < p.nbr_sprite)
	{
		p = ft_init_sprite(p, i);
		p = ft_sdraw(p, s, d, y);
		i++;
	}
	return (p);
}
