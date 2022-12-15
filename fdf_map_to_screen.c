/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:11 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 14:18:21 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_colorset_screen(t_mlx *data)
{
	float	x;
	float	y;

	if (WIN_WIDTH < 400 || WIN_HEIGHT < 400)
		return ;
	x = 50;
	while (x < 305)
	{
		y = 25;
		while (y < 50)
		{
			fdf_put_pixel(data, data->colors[(int)x - 50], data->img.str + 
				((long)(y)*(long)data->img.size_line) + 
				((long)(WIN_WIDTH - 355 + x)*(long)(data->img.bpp / 8)));
			y++;
		}
		x++;
	}
	
}


int	fdf_map_to_screen(t_mlx *data)
{
	size_t	width;
	size_t	height;
	
	fdf_map_fill(data);
	fdf_fill_img(data);
	mlx_clear_window(data->ptr, data->win);
	fdf_colorset_screen(data);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	width = 25;
	height = 25;
	mlx_string_put(data->ptr, data->win, width, height * 1, ORANGE, "Zoom : Mouse Up / Mouse Down");
	mlx_string_put(data->ptr, data->win, width, height * 2, ORANGE, "Rotation & Inclinaison : keyboard arrows");
	mlx_string_put(data->ptr, data->win, width, height * 3, ORANGE, "Translation : W A S D");
	mlx_string_put(data->ptr, data->win, width, height * 4, ORANGE, "Change color : C");
	mlx_string_put(data->ptr, data->win, width, height * 5, ORANGE, "Default view : R");
	mlx_string_put(data->ptr, data->win, width, height * 6, ORANGE, "View from above : SPACE");

	

	return (1);
}
