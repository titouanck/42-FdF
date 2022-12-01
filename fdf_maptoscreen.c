/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maptoscreen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:15 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 15:21:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_fill_pixel(char *pixel, int endian, int color)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	rrgb(color, &red, &green, &blue);
	if (endian == 1)
	{
		*(pixel + 0) = 0;
		*(pixel + 1) = red;
		*(pixel + 2) = green;
		*(pixel + 3) = blue;
	}
	else if (endian == 0)
	{
		*(pixel + 3) = 0;
		*(pixel + 2) = red;
		*(pixel + 1) = green;
		*(pixel + 0) = blue;
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
	int		color;

	y = -1;
	while ((++y / SCALE) < map->height)
	{
		x = -1;
		while ((++x / SCALE) < map->width)
		{
			pixel = buffer + (map->size_line * y) + x * (map->bpp / 8);
			color = (float)(map->map)[x / SCALE][y / SCALE] * 25.5;
			color = rgb(color, color, color);
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
