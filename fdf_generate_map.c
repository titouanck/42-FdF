/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 11:56:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_map_fill_z(t_mapctr *mapctr, int fd)
{
	long	x;
	long	y;
	long	i;
	char	*line;

	y = -1;
	while (++y < mapctr->height)
	{
		line = get_next_line(fd);
		i = 0;
		x = 0;
		while (x < mapctr->width)
		{
			if (line[i] != ' ' && line[i] != '\n')
			{
				((mapctr->map)[x++][y]).z = (float)ft_atoi(line + i);
				while (line[i] && line[i] != ' ' && line[i] != '\n')
					i++;
			}
			else
				i++;
		}
		free(line);
	}
}

void	fdf_map_fill_xy(t_mapctr *mapctr, float scale)
{
	long	x;
	long	y;
	float	xorigin;
	float	yorigin;

	xorigin = (((float)mapctr->width - 1.0) / 2) * scale;
	yorigin = (((float)mapctr->height - 1.0) / 2) * scale;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x = x * scale - xorigin;
			((mapctr->map)[x][y]).y = y * scale - yorigin;
		}
	}
}

t_point	**fdf_generate_map(int fd, t_mlx *mlxdata, t_mapctr *mapctr)
{
	t_point		**map;
	long		i;

	if (fd == -1 || mapctr->width <= 0 || mapctr->height <= 0)
		return (NULL);
	map = ft_calloc(sizeof(t_point *), mapctr->width + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i < mapctr->width)
	{
		map[i] = ft_calloc(sizeof(t_point), mapctr->height);
		if (!map[i])
			fdf_free_map(map);
		i++;
	}
	mapctr->map = map;
	fdf_map_fill_z(mapctr, fd);
	fdf_findrange(mapctr);
	return (map);
}
