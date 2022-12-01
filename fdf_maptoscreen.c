/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maptoscreen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:15 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/02 00:51:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_fill_pixel(char *pixel, int endian, int color)
{
	t_color	tcolor;

	tcolor = rrgb(color);
	if (endian == 1)
	{
		*(pixel + 0) = 0;
		*(pixel + 1) = tcolor.r;
		*(pixel + 2) = tcolor.g;
		*(pixel + 3) = tcolor.b;
	}
	else if (endian == 0)
	{
		*(pixel + 3) = 0;
		*(pixel + 2) = tcolor.r;
		*(pixel + 1) = tcolor.g;
		*(pixel + 0) = tcolor.b;
	}
	else
		return (0);
	return (1);
}

static void	fdf_fill_img(t_map *map, char *buffer)
{
	int		x;
	int		y;
	char	*pixel;
	long	color;
	int		*colortab;

	colortab = fdf_generatecolortab();
	y = -1;
	while ((++y / SCALE) < map->height)
	{
		x = -1;
		while ((++x / SCALE) < map->width)
		{
			pixel = buffer + (map->size_line * y) + x * (map->bpp / 8);
			color = colortab[((long)map->range - (map->max - (map->map)[x / SCALE][y / SCALE])) * 510 / map->range];
			// printf("min : %d | max : %d | range : %ld\n", map->min, map->max, map->range);
			if (!fdf_fill_pixel(pixel, map->endian, color))
				break ;
		}
	}
}

void	fdf_maptoscreen(t_map *map, void *mlx_ptr)
{
	void	*win_ptr;
	int		x;
	int		y;
	char	*addr;
	size_t	pixel;

	win_ptr = mlx_new_window \
		(mlx_ptr, (map->width * SCALE), (map->height * SCALE), "FdF");
	pixel = (map->size_line * y) + x * (map->bpp / 8);
	fdf_fill_img(map, map->buf);
	mlx_put_image_to_window(mlx_ptr, win_ptr, map->img, 0, 0);
	mlx_loop(mlx_ptr);
}
