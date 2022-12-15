/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:11 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/14 13:28:20 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_map_to_screen(t_mlx *data)
{
	size_t	width;
	size_t	height;
	
	fdf_map_fill(data);
	fdf_fill_img(data);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	width = 25;
	height = 25;
	mlx_string_put(data->ptr, data->win, width, height * 1, ORANGE, "Zoom : Mouse Up / Mouse Down");
	mlx_string_put(data->ptr, data->win, width, height * 2, ORANGE, "Rotation : keyboard arrows");
	mlx_string_put(data->ptr, data->win, width, height * 3, ORANGE, "Translation : W A S D");
	mlx_string_put(data->ptr, data->win, width, height * 4, ORANGE, "Change color : C");
	mlx_string_put(data->ptr, data->win, width, height * 5, ORANGE, "Go back to default : R");
	mlx_string_put(data->ptr, data->win, width, height * 6, ORANGE, "Flat view : SPACE");
	return (1);
}
