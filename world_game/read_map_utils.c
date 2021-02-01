/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:55:03 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 18:55:01 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ft_screen(t_player *p, char **tab)
{
	if (ft_check_r(&tab[1]))
		return (-1);
	if (ft_atoi(tab[1]) > 0 && ft_atoi(tab[2]) > 0)
	{
		if (ft_atoi(tab[1]) > 2900)
			p->w = 2900;
		else
			p->w = ft_atoi(tab[1]);
		if (ft_atoi(tab[2]) > 1550)
			p->h = 1550;
		else
			p->h = ft_atoi(tab[2]);
		return (0);
	}
	return (-1);
}

int		ft_texture(t_player *p, char **tab)
{
	if (!ft_cmpr(tab[0], "NO"))
	{
		if (!(p->no = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!ft_cmpr(tab[0], "SO"))
	{
		if (!(p->so = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!ft_cmpr(tab[0], "WE"))
	{
		if (!(p->we = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!ft_cmpr(tab[0], "EA"))
	{
		if (!(p->ea = ft_strdup(tab[1])))
			return (-101);
	}
	else
		return (-2);
	return (0);
}

int		ft_check_cor(char *tab)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == ',')
			count++;
		i++;
	}
	if (count > 3)
		return (1);
	i = 0;
	while (tab[i])
	{
		if ((tab[i] > '9' || tab[i] < '0') && tab[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

int		ft_sol_plafond(t_player *p, char **tab)
{
	char	**tmp;
	int		i;

	if (ft_check_cor(tab[1]) == 1)
		return (-3);
	if (!(tmp = ft_split(tab[1], ',')))
		return (-3);
	if (!ft_cmpr(tab[0], "F"))
		p->f_color = rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	if (!ft_cmpr(tab[0], "C"))
		p->c_color = rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	if (p->f_color == -1 || p->c_color == -1)
		return (-3);
	return (0);
}

int		ft_world_map(t_player *p, char *line)
{
	char *tmp;

	if (!(p->world))
	{
		if (!(p->world = ft_strdup("")))
			return (-101);
	}
	tmp = p->world;
	if (!(p->world = ft_strjoin(p->world, line)))
	{
		free(tmp);
		return (-101);
	}
	free(tmp);
	tmp = p->world;
	if (!(p->world = ft_strjoin(p->world, "\n")))
		return (-101);
	free(tmp);
	tmp = NULL;
	return (0);
}
