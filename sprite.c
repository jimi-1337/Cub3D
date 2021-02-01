/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:54:18 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:57 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_player	sort_sprite(t_player p)
{
	int i;
	int j;
	int v;
	int z;

	i = 1;
	j = 0;
	while (i < p.nbr_sprite)
	{
		v = p.spritedistance[i];
		z = p.spriteorder[i];
		j = i;
		while (j > 0 && p.spritedistance[j - 1] < v)
		{
			p.spritedistance[j] = p.spritedistance[j - 1];
			p.spriteorder[j] = p.spriteorder[j - 1];
			j = j - 1;
		}
		p.spritedistance[j] = v;
		p.spriteorder[j] = z;
		i++;
	}
	return (p);
}

t_player	alloc_sprite(t_player p)
{
	if (p.nbr_sprite > 0)
	{
		if (!(p.sprite = malloc(sizeof(t_vect) * (p.nbr_sprite))))
		{
			p.erreur = -100;
			msg_erreur(p);
		}
		if (!(p.spriteorder = malloc(sizeof(int) * (p.nbr_sprite))))
		{
			p.erreur = -100;
			msg_erreur(p);
		}
		if (!(p.spritedistance = malloc(sizeof(float) * (p.nbr_sprite))))
		{
			p.erreur = -100;
			msg_erreur(p);
		}
	}
	return (p);
}

t_player	remplir_pos(t_player p)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < p.mapheight)
	{
		j = 0;
		while (j < p.mapwidth)
		{
			if (p.world_map[i][j] == '2')
			{
				p.sprite[k].x = (float)i + 0.3;
				p.sprite[k].y = (float)j + 0.3;
				k++;
			}
			j++;
		}
		i++;
	}
	return (p);
}

t_player	pos_sprite(t_player p)
{
	int i;
	int j;

	i = 0;
	while (i < p.mapheight)
	{
		j = 0;
		while (j < p.mapwidth)
		{
			if (p.world_map[i][j] == '2')
				p.nbr_sprite++;
			j++;
		}
		i++;
	}
	p = alloc_sprite(p);
	p = remplir_pos(p);
	return (p);
}
