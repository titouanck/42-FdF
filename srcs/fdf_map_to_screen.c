/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:11 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/06 10:17:53 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_colorset_screen(t_mlx *data)
{
	int	x;
	int	y;

	if (WIN_WIDTH < 1000 || WIN_HEIGHT < 500)
		return ;
	x = 0;
	while (x < 255)
	{
		y = 0;
		while (y < 25)
		{
			fdf_put_pixel(data, data->colors[x], data->img.str \
	+ ((long)(y + 25)*(long)data->img.size_line) \
	+ ((long)(WIN_WIDTH - 255 + x - 35)*(long)(data->img.bpp / 8)));
			y++;
		}
		x++;
	}
}

int	fdf_map_to_screen(t_mlx *data)
{
	fdf_map_fill(data);
	fdf_fill_img(data);
	fdf_colorset_screen(data);
	mlx_clear_window(data->ptr, data->win);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	return (1);
}
