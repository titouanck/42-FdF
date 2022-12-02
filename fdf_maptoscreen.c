/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maptoscreen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:15 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/02 16:22:00 by tchevrie         ###   ########.fr       */
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

static void	fdf_fill_img(t_map *map, char *buffer, float scale)
{
	int		x;
	int		y;
	char	*pixel;
	long	color;
	int		*colortab;

	colortab = fdf_generatecolortab();
	y = -1;
	while ((++y) / PX_RPR / scale < map->height)
	{
		x = -1;
		while ((++x) / PX_RPR / scale < map->width)
		{
			pixel = buffer + (map->size_line * y) + x * (map->bpp / 8);
			color = colortab [((long)map->range - (map->max - (map->map) \
					[(size_t)(x / PX_RPR / scale)] \
					[(size_t)(y / PX_RPR / scale)])) \
					* 510 / map->range];
			// (map->map) \
			// 		[(size_t)((float)x / (float)PX_RPR / scale)] \
			// 		[(size_t)((float)y / (float)PX_RPR / scale)] = 0;
			// printf(">> [%lu] || [%lu] <<\n", (size_t)((float)x / (float)PX_RPR / scale), (size_t)((float)x / (float)PX_RPR / scale));
			// printf("x = %d | y = %d | scale = %f ||| %f\n", x, y, scale, ((float)x / (float)PX_RPR / scale));
			// printf("%lu\n", (size_t)((float)x / (float)PX_RPR / scale));
			if ((int)((float)x / scale) % PX_RPR == 0 || (int)((float)y / scale) % PX_RPR == 0 || (int)((float)x / scale) % PX_RPR == PX_RPR - 1 || (int)((float)y / scale) % PX_RPR == PX_RPR - 1)
				fdf_fill_pixel(pixel, map->endian, color);
			// // if (!fdf_fill_pixel(pixel, map->endian, color))
			// // 	break ;
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
	float	scale;

	scale = fdf_defscale(map->width, map->height);
	win_ptr = mlx_new_window(mlx_ptr, SCREEN_W, SCREEN_H, "FdF");
	// pixel = (map->size_line * y) + x * (map->bpp / 8);
	fdf_fill_img(map, map->buf, scale);
	mlx_put_image_to_window(mlx_ptr, win_ptr, map->img, (SCREEN_W / 2) - (map->width * PX_RPR * scale / 2), (SCREEN_H / 2) - (map->height * PX_RPR * scale / 2));
	mlx_loop(mlx_ptr);
}
