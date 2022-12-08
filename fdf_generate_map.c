/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 00:40:32 by tchevrie         ###   ########.fr       */
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

static void	fdf_map_fill_xy(t_mapctr *mapctr, float scale)
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

static void	fdf_map_rotation(t_mapctr *mapctr, float deg)
{
	long	x;
	long	y;
	float	old_x;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			old_x = ((mapctr->map)[x][y]).x;
			((mapctr->map)[x][y]).x = old_x * \
					cos(deg / 57.2958) + ((mapctr->map)[x][y]).y * \
					(sin(deg / 57.2958) * -1);
			((mapctr->map)[x][y]).y = old_x * \
					sin(deg / 57.2958) + ((mapctr->map)[x][y]).y * \
					cos(deg / 57.2958);
		}
	}
}

static void	fdf_map_inclinaison(t_mapctr *mapctr, float ix, float iy)
{
	long	x;
	long	y;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x *= ix;
			((mapctr->map)[x][y]).y *= iy;
		}
	}
}

static void	fdf_map_center(t_mapctr *mapctr)
{
	long	x;
	long	y;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x += WIN_WIDTH / 2;
			((mapctr->map)[x][y]).y += WIN_HEIGHT / 2;
		}
	}
}

static void	fdf_map_relief(t_mapctr *mapctr, float scale, float deg)
{
	long	x;
	long	y;
	float	in_range;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			in_range = (((((float)mapctr->range - ((float)mapctr->max - (float)(mapctr->map[x][y].z))) / (float)mapctr->range) * 0.5) * scale);
			((mapctr->map)[x][y]).x -= in_range;
			((mapctr->map)[x][y]).y -= in_range;
		}
	}
}

void	fdf_map_fill(t_mlx *data)
{
	fdf_map_fill_xy(&(data->mapctr), data->scale);
	fdf_map_rotation(&(data->mapctr), data->deg);
	fdf_map_inclinaison(&(data->mapctr), data->ix, data->iy);
	fdf_map_relief(&(data->mapctr), data->scale, data->deg);
	fdf_map_center(&(data->mapctr));
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
