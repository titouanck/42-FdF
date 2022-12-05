/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/05 17:47:03 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_map_fill(int **map, int fd, int width, int height)
{
	size_t	x;
	size_t	y;
	size_t	i;
	char	*line;

	y = -1;
	while (++y < height)
	{
		line = get_next_line(fd);
		i = 0;
		x = 0;
		while (x < width)
		{
			if (line[i] != ' ' && line[i] != '\n')
			{
				map[x++][y] = ft_atoi(line + i);
				while (line[i] && line[i] != ' ' && line[i] != '\n')
					i++;
			}
			else
				i++;
		}
		free(line);
	}
}

int	**fdf_generate_map(int fd, t_mapctr *mapctr)
{
	int		**map;
	size_t	i;

	if (fd == -1 || mapctr->width <= 0 || mapctr->height <= 0)
		return (NULL);
	map = ft_calloc(sizeof(int *), mapctr->width + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i < mapctr->width)
	{
		map[i] = ft_calloc(sizeof(int), mapctr->height);
		if (!map[i])
			fdf_free_map(map);
		i++;
	}
	fdf_map_fill(map, fd, mapctr->width, mapctr->height);
	return (map);
}
