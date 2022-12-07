/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/07 18:19:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define ANGLE 0

static float	deg_conversion(float deg)
{
	float	angle;

	while (deg - 360 >= 0)
		deg -= 360;
	if (deg <= 180)
		angle = deg / 90;
	else if (deg <= 360)
		angle = (2 - ((deg - 180) / 90)) * -1;
	return (angle);
}

static void	fdf_map_fill(t_mapctr *mapctr, int fd, float scale, float deg)
{
	size_t	x;
	size_t	y;
	size_t	i;
	char	*line;
	float	angle;

	angle = deg_conversion(deg);
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
				// ((mapctr->map)[x][y]).x = ((hypot(mapctr->height * scale, mapctr->height * scale)) / 2) + (x * ((hypot(scale, scale) * PERSPECTIVE) / 2)) - (y * ((hypot(scale, scale) * PERSPECTIVE) / 2));
				// ((mapctr->map)[x][y]).y = (x * ((hypot(scale, scale)) / 2)) + (y * ((hypot(scale, scale)) / 2));
				if (angle >= 0)
				{
					if (angle <= 1)
					{
						((mapctr->map)[x][y]).x = 1000 + ((x * scale) * (1 - angle)) - (angle * (y * scale));
						((mapctr->map)[x][y]).y = 400 + ((y * scale) * (1 - angle)) + (angle * (x * scale));
					}
					else
					{
						((mapctr->map)[x][y]).x = 1000 - (y * scale) - ((x * scale) * ((angle - 1))) + ((angle - 1) * (y * scale));
						((mapctr->map)[x][y]).y = 400 + (x * scale) - ((y * scale) * ((angle - 1))) - ((angle - 1) * (x * scale));
					}
				}
				else
				{
					if (angle >= -1)
					{
						((mapctr->map)[x][y]).x = 1000 + ((x * scale) * (1 - (angle * -1))) + ((angle * -1) * (y * scale));
						((mapctr->map)[x][y]).y = 400 + ((y * scale) * (1 - (angle * -1))) - ((angle * -1) * (x * scale));
					}
					else
					{
						((mapctr->map)[x][y]).x = 1000 + (y * scale) - ((x * scale) * (((angle + 1) * -1))) - (((angle + 1) * -1) * (y * scale));
						((mapctr->map)[x][y]).y = 400 - (x * scale) - ((y * scale) * (((angle + 1) * -1))) + (((angle + 1) * -1) * (x * scale));
					}
				}
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

t_point	**fdf_generate_map(int fd, t_mapctr *mapctr, float scale)
{
	t_point		**map;
	size_t	i;

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
	fdf_map_fill(mapctr, fd, scale, 0);
	return (map);
}
