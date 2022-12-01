/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:43:37 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 19:17:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	// fdf_maptoscreen(map, mlx_ptr);
	return (fdf_lstmap_free(mlx_ptr, map), 1);
}
