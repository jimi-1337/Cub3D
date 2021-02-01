/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:54:11 by amoujane          #+#    #+#             */
/*   Updated: 2020/02/21 17:24:41 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		bitmap_info_header(t_player *p, int fd)
{
	int head_info_size;
	int plane_nbr;
	int o_count;

	head_info_size = 40;
	plane_nbr = 1;
	write(fd, &head_info_size, 4);
	write(fd, &p->w, 4);
	write(fd, &p->h, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &p->win.bpp, 2);
	o_count = 0;
	while (o_count < 24)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (0);
}

int		invers_pixel(t_player *p, int line_cnt)
{
	int save;
	int i;
	int j;

	i = (p->w * line_cnt) + p->w - 1;
	j = p->w * line_cnt;
	while (j < i)
	{
		save = p->win.data[i];
		p->win.data[i] = p->win.data[j];
		p->win.data[j] = save;
		j++;
		i--;
	}
	return (0);
}

int		ft_invers(t_player *p)
{
	int line_cnt;

	line_cnt = 0;
	while (line_cnt < p->h)
	{
		invers_pixel(p, line_cnt);
		line_cnt++;
	}
	return (0);
}

int		data_to_bitmap(t_player *p, int fd)
{
	int i;

	i = p->h * p->w - 1;
	while (i >= 0)
	{
		write(fd, &p->win.data[i], 4);
		i--;
	}
	return (0);
}

int		create_bitmap(t_player *p, char *name)
{
	int fd;
	int file_size;
	int first_pix;

	if ((fd = open(name, O_CREAT | O_RDWR, 0777)) < 0)
		ft_putstr("Error\nerreur de creation de bmp");
	file_size = 14 + 40 + (p->h * p->w * 4);
	first_pix = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(p, fd);
	ft_invers(p);
	data_to_bitmap(p, fd);
	close(fd);
	return (0);
}
