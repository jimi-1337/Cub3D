/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:55:36 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:43:22 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*split_space(char *tab)
{
	char	*t;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] != ' ')
			j++;
		i++;
	}
	if (!(t = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] != ' ')
			t[j++] = tab[i];
		i++;
	}
	t[j] = '\0';
	return (t);
}

int		nbr_ch(char **s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

int		ft_cmpr(char *s, char *t)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) != ft_strlen(t))
		return (1);
	while (s[i])
	{
		if (s[i] != t[i])
			return (1);
		i++;
	}
	return (0);
}

int		rgb(int r, int g, int b)
{
	int result;

	if (r > 255 || g > 255 || b > 255
			|| r < 0 || g < 0 || b < 0)
		return (-1);
	result = 0;
	result += r << 16;
	result += g << 8;
	result += b;
	return (result);
}

int		worldmap(t_player *p, char **t)
{
	int j;

	j = 0;
	while (t[j])
	{
		if (!(p->world_map[j] = split_space(t[j])))
		{
			while (t[j])
			{
				free(t[j]);
				j++;
			}
			free(t);
			return (-1);
		}
		free(t[j]);
		j++;
	}
	p->world_map[j] = 0;
	free(t);
	return (1);
}
