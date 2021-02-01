/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:53:45 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 19:12:14 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			ft_exit(void)
{
	ft_putstr("Error\nfichier invalide");
	exit(0);
}

int				ft_check_r(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && (tab[i][j] <= '9' && tab[i][j] >= '0'))
			j++;
		if (tab[i][j] != '\0')
			return (1);
		i++;
	}
	return (0);
}

t_player		init_player(t_player *p)
{
	p->erreur = 0;
	p->w = 0;
	p->h = 0;
	p->f_color = 0;
	p->c_color = 0;
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->s = NULL;
	p->world = NULL;
	p->world_map = NULL;
	p->sprite = NULL;
	p->spriteorder = NULL;
	p->spritedistance = NULL;
	p->nbr_sprite = 0;
	return (*p);
}
