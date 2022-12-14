/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:59:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/14 03:33:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clear_img(t_mlx *data)
{
	mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = mlx_new_image(data->ptr, \
			WIN_WIDTH * 2, WIN_HEIGHT * 2);
}

// {
// 	long	x;
// 	long	y;
// 	t_point	current;

// 	y = -1;
// 	while (++y < mapctr->height)
// 	{
// 		x = -1;
// 		while (++x < mapctr->width)
// 		{
// 			current = data->mapctr.map[x][y];
// 			fdf_put_pixel(data, BLACK, data->img.str + \
// 				((long)(current.y)*(long)data->img.size_line) + \
// 				((long)(current.x)*(long)(data->img.bpp / 8)));
// 			if (x > 0)
// 				fdf_clearlines(data, data->mapctr.map[x - 1][y], current);
// 			if (y > 0)
// 				fdf_clearlines(data, data->mapctr.map[x][y - 1], current);
// 		}
// 	}
// }
