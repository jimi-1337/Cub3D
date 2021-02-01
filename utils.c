/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:54:26 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:03:03 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	i = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (i < n && a1[i] == a2[i])
		i++;
	if (i == n)
		return (0);
	return (a1[i] - a2[i]);
}

int		ft_signe(const char *s)
{
	int sig;

	sig = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sig = -1;
	}
	return (sig);
}

int		ft_atoi(const char *s)
{
	int				signe;
	long long int	result;
	long long int	val;

	result = 0;
	val = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\r' || *s == '\v'
				|| *s == '\f' || *s == '\n') && *s)
		s++;
	signe = ft_signe(s);
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		val = result;
		result = (result * 10) + ((*s - '0') * (signe));
		if (signe == 1 && result < val)
			return (-1);
		if (signe == -1 && result > val)
			return (0);
		s++;
	}
	return (result);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)s;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}
