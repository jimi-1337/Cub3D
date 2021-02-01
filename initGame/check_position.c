/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:52:42 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:18:51 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player	position_check1(t_player p, int i, int j)
{
	if (p.world_map[i][j] == 'N')
	{
		p.dir.x = -1;
		p.dir.y = 0;
		p.plane.x = 0;
		p.plane.y = 0.66;
		p.pos.x = (float)i + 0.2;
		p.pos.y = (float)j + 0.2;
		p.world_map[i][j] = '0';
	}
	if (p.world_map[i][j] == 'S')
	{
		p.dir.x = 1;
		p.dir.y = 0;
		p.plane.x = 0;
		p.plane.y = -0.66;
		p.pos.x = (float)i + 0.2;
		p.pos.y = (float)j + 0.2;
		p.world_map[i][j] = '0';
	}
	return (p);
}

t_player	position_check2(t_player p, int i, int j)
{
	if (p.world_map[i][j] == 'E')
	{
		p.dir.x = 0;
		p.dir.y = 1;
		p.plane.x = 0.66;
		p.plane.y = 0;
		p.pos.x = (float)i + 0.2;
		p.pos.y = (float)j + 0.2;
		p.world_map[i][j] = '0';
	}
	if (p.world_map[i][j] == 'W')
	{
		p.dir.x = 0;
		p.dir.y = -1;
		p.plane.x = -0.66;
		p.plane.y = 0;
		p.pos.x = (float)i + 0.2;
		p.pos.y = (float)j + 0.2;
		p.world_map[i][j] = '0';
	}
	return (p);
}

t_player	check_positon(t_player p)
{
	int i;
	int j;

	i = 0;
	while (p.world_map[i])
	{
		j = 0;
		while (p.world_map[i][j])
		{
			p = position_check1(p, i, j);
			p = position_check2(p, i, j);
			j++;
		}
		i++;
	}
	return (p);
}
