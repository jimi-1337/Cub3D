/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:53:32 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:48 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	calcul_mot(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

static char	**ft_allo(char **t, char const *s, char c, int n)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (i < n && s[j])
	{
		k = 0;
		while (s[j] && s[j] != c)
		{
			k++;
			j++;
		}
		if (k != 0)
		{
			if (!(t[i] = (char *)malloc(sizeof(char) * (k + 1))))
				return (NULL);
			i++;
		}
		j++;
	}
	t[n] = 0;
	return (t);
}

static void	ft_remp(char **t, char const *s, char c, int n)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < n && s[j])
	{
		k = 0;
		if (s[j] != c)
		{
			while (s[j] && s[j] != c)
			{
				t[i][k] = s[j];
				k++;
				j++;
			}
			t[i][k] = '\0';
			i++;
		}
		else
			j++;
	}
}

char		**ft_split(char const *s, char c)
{
	int		n;
	char	**t;

	if (s == NULL)
		return (NULL);
	n = calcul_mot(s, c);
	if (!(t = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	t = ft_allo(t, s, c, n);
	ft_remp(t, s, c, n);
	return (t);
}
