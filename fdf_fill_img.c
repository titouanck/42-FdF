/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:22 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/13 17:16:39 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_fill_img(t_mlx *data)
{
	int		x;
	int		y;
	t_point	current;

	y = -1;
	while (++y < data->mapctr.height)
	{
		x = -1;
		while (++x < data->mapctr.width)
		{
			current = data->mapctr.map[x][y];
			if (current.x >= 0 && current.x < WIN_WIDTH \
					&& current.y >= 0 && current.y < WIN_HEIGHT)
			{
				fdf_put_pixel(data, current.color, data->img.str + \
						((long)(current.y)*(long)data->img.size_line) + \
						((long)(current.x)*(long)(data->img.bpp / 8)));
			}
			if (x > 0)
				fdf_bresenham(data, data->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_bresenham(data, data->mapctr.map[x][y - 1], current);
		}
	}
	printf("fdf_fill_img() -> OK!\n");
}
