/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:51:31 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:16 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player	ft_init(t_player p)
{
	p.map.x = (int)p.pos.x;
	p.map.y = (int)p.pos.y;
	p.deltadist.x = fabs(1 / p.raydir.x);
	p.deltadist.y = fabs(1 / p.raydir.y);
	if (p.raydir.x < 0)
	{
		p.step.x = -1;
		p.sidedist.x = (p.pos.x - p.map.x) * p.deltadist.x;
	}
	else
	{
		p.step.x = 1;
		p.sidedist.x = (p.map.x + 1.0 - p.pos.x) * p.deltadist.x;
	}
	if (p.raydir.y < 0)
	{
		p.step.y = -1;
		p.sidedist.y = (p.pos.y - p.map.y) * p.deltadist.y;
	}
	else
	{
		p.step.y = 1;
		p.sidedist.y = (p.map.y + 1.0 - p.pos.y) * p.deltadist.y;
	}
	return (p);
}

t_player	detect_wall(t_player p)
{
	p.hit = 0;
	while (p.hit == 0)
	{
		if (p.sidedist.x < p.sidedist.y)
		{
			p.sidedist.x += p.deltadist.x;
			p.map.x += p.step.x;
			p.side = 0;
		}
		else
		{
			p.sidedist.y += p.deltadist.y;
			p.map.y += p.step.y;
			p.side = 1;
		}
		if (p.world_map[p.map.x][p.map.y] != '0' &&
				p.world_map[p.map.x][p.map.y] != '2')
			p.hit = 1;
	}
	if (p.side == 0)
		p.perpwalldist = (p.map.x - p.pos.x + (1 - p.step.x) / 2) / p.raydir.x;
	else
		p.perpwalldist = (p.map.y - p.pos.y + (1 - p.step.y) / 2) / p.raydir.y;
	return (p);
}

t_player	sol_plafond_reinit(t_player p, int x, int n)
{
	p.d.wlineheight = (int)(p.h / p.perpwalldist);
	p.d.wdrawstart = ((-p.d.wlineheight) / 2) + p.h / 2;
	if (p.d.wdrawstart < 0)
		p.d.wdrawstart = 0;
	p.d.wdrawend = p.d.wlineheight / 2 + p.h / 2;
	if (p.d.wdrawend >= p.h)
		p.d.wdrawend = p.h - 1;
	if (p.side == 0)
		p.d.wallx = p.pos.y + p.perpwalldist * p.raydir.y;
	else
		p.d.wallx = p.pos.x + p.perpwalldist * p.raydir.x;
	p.d.wallx -= floor((p.d.wallx));
	n = (int)p.h / 2;
	while (n < p.h)
	{
		p.win.data[x + n * p.w] = p.f_color;
		n++;
	}
	n = 0;
	while (n < ((int)p.h / 2))
	{
		p.win.data[x + n * p.w] = p.c_color;
		n++;
	}
	return (p);
}

t_player	draw_texture(t_player p, int x, int y)
{
	p.d.wtexx = (int)(p.d.wallx * (float)(TEX_WIDTH));
	if (p.side == 0 && p.raydir.x > 0)
		p.d.wtexx = TEX_WIDTH - p.d.wtexx - 1;
	if (p.side == 1 && p.raydir.y < 0)
		p.d.wtexx = TEX_WIDTH - p.d.wtexx - 1;
	y = p.d.wdrawstart;
	while (y < p.d.wdrawend)
	{
		p.d.wtexy = (int)((y * 2 - p.h + p.d.wlineheight) *
				(TEX_HEIGHT / 2) / p.d.wlineheight);
		if (p.side == 0 && p.pos.x < p.map.x)
			p.d.wcolor = p.win.data_texn[p.d.wtexx + p.d.wtexy * TEX_WIDTH];
		else if (p.side == 0 && p.pos.x >= p.map.x)
			p.d.wcolor = p.win.data_texs[p.d.wtexx + p.d.wtexy * TEX_WIDTH];
		else if (p.side == 1 && p.pos.y < p.map.y)
			p.d.wcolor = p.win.data_texw[p.d.wtexx + p.d.wtexy * TEX_WIDTH];
		else if (p.side == 1 && p.pos.y >= p.map.y)
			p.d.wcolor = p.win.data_texe[p.d.wtexx + p.d.wtexy * TEX_WIDTH];
		p.win.data[x + y * p.w] = p.d.wcolor;
		y++;
	}
	return (p);
}

t_player	draw_wall(t_player p)
{
	int		x;
	int		n;

	x = 0;
	n = 0;
	p.zbuff = malloc(sizeof(float) * p.w);
	while (x < p.w)
	{
		p.camerax = (2 * x) / (float)p.w - 1;
		p.raydir.x = p.dir.x + p.plane.x * p.camerax;
		p.raydir.y = p.dir.y + p.plane.y * p.camerax;
		p = ft_init(p);
		p = detect_wall(p);
		p = sol_plafond_reinit(p, x, n);
		p = draw_texture(p, x, n);
		p.zbuff[x] = p.perpwalldist;
		x++;
	}
	return (p);
}
