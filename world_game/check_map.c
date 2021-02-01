/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:54:56 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:18:49 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_map(t_player *p)
{
	int		j;
	int		r;
	char	**t;

	j = 0;
	r = 0;
	while (p->world[r])
	{
		while (p->world[r] != '\n' && p->world[r])
			r++;
		r++;
		j++;
	}
	if (!(p->world_map = malloc(sizeof(char *) * (j + 1))) ||
			!(t = ft_split(p->world, '\n')))
		return (-1);
	return (worldmap(p, t));
}

int		map_ferme(t_player *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (p->world_map[0][j])
	{
		if (p->world_map[0][j] != '1' ||
				p->world_map[p->mapheight - 1][j] != '1')
			return (-1);
		j++;
	}
	while (p->world_map[i])
	{
		if (p->world_map[i][0] != '1' ||
				p->world_map[i][p->mapwidth - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int		check_map2(t_player *p)
{
	int		i;
	int		j;

	i = 0;
	if (map_ferme(p) == -1)
		return (-1);
	while (p->world_map[i])
	{
		j = 0;
		while (p->world_map[i][j])
		{
			if (p->world_map[i][j] != '0' && p->world_map[i][j] != '1'
					&& p->world_map[i][j] != '2' && p->world_map[i][j] != 'N'
					&& p->world_map[i][j] != 'E' && p->world_map[i][j] != 'W'
					&& p->world_map[i][j] != 'S')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_map3(t_player *p)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (p->world_map[i])
	{
		if (ft_chr(p->world_map[i], 'N') || ft_chr(p->world_map[i], 'E')
				|| ft_chr(p->world_map[i], 'S') || ft_chr(p->world_map[i], 'W'))
			k++;
		i++;
	}
	if (k != 1)
		return (-1);
	return (0);
}

int		check_game(t_player *p)
{
	int		i;

	i = 0;
	if (check_map(p) == -1)
		return (-4);
	while (p->world_map[i])
		i++;
	p->mapheight = i;
	i = 0;
	while (p->world_map[0][i])
		i++;
	p->mapwidth = i;
	i = 0;
	while (p->world_map[i])
	{
		if ((int)ft_strlen(p->world_map[i]) != p->mapwidth)
			return (-4);
		i++;
	}
	if (check_map2(p) == -1)
		return (-4);
	if (check_map3(p) == -1)
		return (-4);
	return (1);
}
