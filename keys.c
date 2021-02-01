/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:53:56 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:51 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_player	free_game(t_player p)
{
	if (p.no)
		free(p.no);
	if (p.so)
		free(p.so);
	if (p.we)
		free(p.we);
	if (p.ea)
		free(p.ea);
	if (p.s)
		free(p.s);
	if (p.sprite)
		free(p.sprite);
	if (p.spriteorder)
		free(p.spriteorder);
	if (p.spritedistance)
		free(p.spritedistance);
	p = init_player(&p);
	return (p);
}

void		keys_ws(int key, t_player *p)
{
	if (key == KEY_W && (p->world_map[(int)(p->pos.x + p->dir.x * 0.2)]
				[(int)(p->pos.y)] == '0'
				|| p->world_map[(int)(p->pos.x + p->dir.x * 0.2)]
				[(int)(p->pos.y)] == '2'))
		p->pos.x += p->dir.x * 0.2;
	if (key == KEY_W && (p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y + p->dir.y * 0.2)] == '0'
				|| p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y + p->dir.y * 0.2)] == '2'))
		p->pos.y += p->dir.y * 0.2;
	if (key == KEY_S && (p->world_map[(int)(p->pos.x - p->dir.x * 0.2)]
				[(int)(p->pos.y)] == '0'
				|| p->world_map[(int)(p->pos.x - p->dir.x * 0.2)]
				[(int)(p->pos.y)] == '2'))
		p->pos.x -= p->dir.x * 0.2;
	if (key == KEY_S && (p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y - p->dir.y * 0.2)] == '0'
				|| p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y - p->dir.y * 0.2)] == '2'))
		p->pos.y -= p->dir.y * 0.2;
}

void		keys_ad(int key, t_player *p)
{
	if (key == KEY_A && (p->world_map[(int)(p->pos.x - p->plane.x * 0.2)]
				[(int)(p->pos.y)] == '0'
				|| p->world_map[(int)(p->pos.x - p->plane.x * 0.2)]
				[(int)(p->pos.y)] == '2'))
		p->pos.x -= p->plane.x * 0.2;
	if (key == KEY_A && (p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y - p->plane.y * 0.2)] == '0'
				|| p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y - p->plane.y * 0.2)] == '2'))
		p->pos.y -= p->plane.y * 0.2;
	if (key == KEY_D && (p->world_map[(int)(p->pos.x + p->plane.x * 0.2)]
				[(int)(p->pos.y)] == '0'
				|| p->world_map[(int)(p->pos.x + p->plane.x * 0.2)]
				[(int)(p->pos.y)] == '2'))
		p->pos.x += p->plane.x * 0.2;
	if (key == KEY_D && (p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y + p->plane.y * 0.2)] == '0'
				|| p->world_map[(int)(p->pos.x)]
				[(int)(p->pos.y + p->plane.y * 0.2)] == '2'))
		p->pos.y += p->plane.y * 0.2;
}

void		keys_lr(int key, t_player *p)
{
	float old_dirx;
	float old_planex;

	if (key == KEY_LEFT)
	{
		old_dirx = p->dir.x;
		p->dir.x = p->dir.x * cos(0.2) - p->dir.y * sin(0.2);
		p->dir.y = old_dirx * sin(0.2) + p->dir.y * cos(0.2);
		old_planex = p->plane.x;
		p->plane.x = p->plane.x * cos(0.2) - p->plane.y * sin(0.2);
		p->plane.y = old_planex * sin(0.2) + p->plane.y * cos(0.2);
	}
	if (key == KEY_RIGHT)
	{
		old_dirx = p->dir.x;
		p->dir.x = p->dir.x * cos(-0.2) - p->dir.y * sin(-0.2);
		p->dir.y = old_dirx * sin(-0.2) + p->dir.y * cos(-0.2);
		old_planex = p->plane.x;
		p->plane.x = p->plane.x * cos(-0.2) - p->plane.y * sin(-0.2);
		p->plane.y = old_planex * sin(-0.2) + p->plane.y * cos(-0.2);
	}
}

int			keys(int key, t_player *p)
{
	keys_ws(key, p);
	keys_ad(key, p);
	keys_lr(key, p);
	if (key == KEY_ESC)
	{
		*p = free_game(*p);
		exit(0);
	}
	draw(*p, 2, NULL);
	return (1);
}
