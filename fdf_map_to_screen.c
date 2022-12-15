/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:11 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 15:24:03 by tchevrie         ###   ########.fr       */
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
			fdf_put_pixel(data, data->colors[x], data->img.str + 
				((long)(y + 25)*(long)data->img.size_line) + 
				((long)(WIN_WIDTH - 255 + x - 35)*(long)(data->img.bpp / 8)));
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
	fdf_colorset_screen(data);
	mlx_clear_window(data->ptr, data->win);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	width = 27;
	height = 25;
	mlx_string_put(data->ptr, data->win, width, height * 1, data->colors[255], "Zoom : Mouse Up / Mouse Down");
	mlx_string_put(data->ptr, data->win, width, height * 2, data->colors[255], "Rotation & Inclinaison : keyboard arrows");
	mlx_string_put(data->ptr, data->win, width, height * 3, data->colors[255], "Translation : W A S D");
	mlx_string_put(data->ptr, data->win, width, height * 4, data->colors[255], "Change color : C");
	mlx_string_put(data->ptr, data->win, width, height * 5, data->colors[255], "Default view : R");
	mlx_string_put(data->ptr, data->win, width, height * 6, data->colors[255], "View from above : SPACE");

	

	return (1);
}
