/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapgenerate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:56 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 19:23:56 by tchevrie         ###   ########.fr       */
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

int	**fdf_mapgenerate(int fd, int width, int height)
{
	int		**map;
	size_t	i;

	if (fd == -1 || width <= 0 || height <= 0)
		return (NULL);
	map = ft_calloc(sizeof(int *), width);
	if (!map)
		return (NULL);
	i = 0;
	while (i < width)
	{
		map[i] = ft_calloc(sizeof(int), height);
		if (!map[i])
			fdf_mapfree(map);
		i++;
	}
	fdf_map_fill(map, fd, width, height);
	return (map);
}
