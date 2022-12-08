/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 16:43:39 by tchevrie         ###   ########.fr       */
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

# define X 20
# define Y 20

# define XX 40
# define YY 80

static void	fdf_map_fill(t_mapctr *mapctr, int fd, float scale, float deg)
{
	size_t	x;
	size_t	y;
	size_t	i;
	char	*line;
	float	tmp;
	float	angle;
	float	xorigin;
	float	yorigin;
	
	xorigin = (((float)mapctr->width - 1.0) / 2) * scale * PERSPECTIVE;
	yorigin = (((float)mapctr->height - 1.0) / 2) * scale * PERSPECTIVE;
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
				((mapctr->map)[x][y]).z = (float)ft_atoi(line + i);
				((mapctr->map)[x][y]).x = 600;
				((mapctr->map)[x][y]).x += ((x * scale * PERSPECTIVE) - xorigin) * cos(deg / 57.2958) + ((y * scale * PERSPECTIVE) - yorigin) * (sin(deg / 57.2958) * -1);
				((mapctr->map)[x][y]).y = 600;
				((mapctr->map)[x][y]).y += ((x * scale) - xorigin) * sin(deg / 57.2958) + ((y * scale) - yorigin) * cos(deg / 57.2958);
				x++;
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
	fdf_map_fill(mapctr, fd, scale, 45);
	return (map);
}
