/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapfindrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:40:40 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 22:47:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_mapfindrange(t_map *map)
{
	size_t	x;
	size_t	y;
	int		current;

	map->min = 0;
	map->max = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			current = (map->map)[x][y];
			if (current < map->min)
				map->min = current;
			if (current > map->max)
				map->max = current;
		}
	}
	map->range = (long) map->max - (long) map->min + 1;
}
