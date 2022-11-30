/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:43:37 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 23:21:11 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_maptoscreen(t_map *map, void *mlx_ptr)
{
	void	*win_ptr;
	int		x;
	int		y;

	win_ptr = mlx_new_window(mlx_ptr, (map->width * 42), (map->height * 42), "MAP 42");
	y = 0;
	while ((y / 42) < map->height)
	{
		x = 0;
		while ((x / 42) < map->width)
		{
			if ((map->map)[(x / 42)][(y / 42)] > 0)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, WHITE);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
}

int	fdf_map3d(char *file)
{
	int		fd;
	void	*mlx_ptr;
	t_map	*map;

	if (!file)
		return (0);
	mlx_ptr = mlx_init();
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_OPEN), 0);
	map = fdf_lstmap_new(mlx_ptr, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		mlx_destroy_image(mlx_ptr, map->img);
		return (ft_printf(ERR_OPEN), 0);
	}
	map->map = fdf_mapgenerate(fd, map->width, map->height);
	close(fd);
	fdf_mapprint(map);
	fdf_maptoscreen(map, mlx_ptr);
	return (1);
}
