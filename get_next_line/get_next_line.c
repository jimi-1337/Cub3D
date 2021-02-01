/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:52:25 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:23 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_read(char *str, char *b, int *n, int fd)
{
	char *tmp;

	while ((*n = read(fd, b, BUFFER_SIZE)) > 0)
	{
		b[*n] = '\0';
		tmp = str;
		str = ft_strjoin(str, b);
		free(tmp);
		if (ft_chr(str, '\n') != 0)
			break ;
	}
	free(b);
	return (str);
}

int		ft_return(char **ch, int n, int fd, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (n < 0)
		return (-1);
	while (ch[fd][i] != '\n' && ch[fd][i] != '\0')
		i++;
	*line = ft_substr(ch[fd], 0, i);
	tmp = ch[fd];
	if (ch[fd][i] == '\0')
	{
		ch[fd] = NULL;
		free(tmp);
		return (0);
	}
	ch[fd] = ft_strdup(ch[fd] + i + 1);
	free(tmp);
	if (!(*line) || !ch[fd])
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			n;
	static char	*ch[256];
	char		*b;

	n = 0;
	if (!(b = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0 || read(fd, b, 0) == -1)
	{
		free(b);
		return (-1);
	}
	if (!ch[fd])
		if (!(ch[fd] = ft_strdup("")))
		{
			free(b);
			return (-1);
		}
	ch[fd] = ft_read(ch[fd], b, &n, fd);
	return (ft_return(ch, n, fd, line));
}
