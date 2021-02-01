/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:55:15 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:45 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_player		*check_er(t_player *p, char *line, char **t, int *n)
{
	if (nbr_ch(t) == 3 && !ft_cmpr(t[0], "R"))
		p->erreur = ft_screen(p, t);
	else if (nbr_ch(t) == 2 && (!ft_cmpr(t[0], "NO") || !ft_cmpr(t[0], "SO")
				|| !ft_cmpr(t[0], "WE") || !ft_cmpr(t[0], "EA")))
		p->erreur = ft_texture(p, t);
	else if (nbr_ch(t) == 2 && !ft_cmpr(t[0], "S"))
	{
		if (!(p->s = ft_strdup(t[1])))
			p->erreur = -101;
	}
	else if (nbr_ch(t) == 2 && (!ft_cmpr(t[0], "F") || !ft_cmpr(t[0], "C")))
		p->erreur = ft_sol_plafond(p, t);
	else if ((ft_atoi(line) && p->no && p->so && p->we && p->ea && p->w
				&& p->h && p->f_color > 0 && p->c_color > 0 && p->s))
	{
		(*n)++;
		p->erreur = ft_world_map(p, line);
	}
	else
		p->erreur = -100;
	return (p);
}

int				fonct(char *line, t_player *p)
{
	char			**tab;
	static int		n;
	int				i;

	tab = NULL;
	if (ft_strlen(line) == 0 && !n)
		return (0);
	if ((ft_strlen(line) == 0) && (n != 0))
		return ((p->erreur = -4));
	if (!ft_atoi(line))
		if (!(tab = ft_split(line, ' ')))
			return ((p->erreur = -101));
	p = check_er(p, line, tab, &n);
	if (tab != NULL)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (p->erreur);
}

t_player		read_from_file(int fd, t_player p)
{
	char	*line;
	int		n;
	int		r;

	n = 1;
	r = 0;
	while (n > 0 && r >= 0)
	{
		n = get_next_line(fd, &line);
		if (n != -1)
		{
			r = fonct(line, &p);
			free(line);
			line = NULL;
		}
	}
	if (n == -1)
		p.erreur = -7;
	return (p);
}
