/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/07 11:59:34 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_map_fill(t_mapctr *mapctr, int fd, float scale)
{
	size_t	x;
	size_t	y;
	size_t	i;
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
				((mapctr->map)[x][y]).x = (hypotf(mapctr->height * scale, mapctr->height * scale) / 2) + (x * (hypotf(scale, scale) / 2)) - (y * (hypotf(scale, scale) / 2));
				((mapctr->map)[x][y]).y = (x * (hypotf(scale, scale) / 2)) + (y * (hypotf(scale, scale) / 2));
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
	fdf_map_fill(mapctr, fd, scale);
	return (map);
}
