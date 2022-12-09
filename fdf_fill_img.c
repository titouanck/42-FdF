/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:22 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 10:56:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_fill_img(t_mlx *data)
{
	int		x;
	int		y;
	t_point	current;

	y = 0;
	while (y < data->mapctr.height)
	{
		x = 0;
		while (x < data->mapctr.width)
		{
			current = data->mapctr.map[x][y];
			if (current.x > -(data->scale) && current.y > -(data->scale) && current.x < (WIN_WIDTH + data->scale) && current.y < (WIN_HEIGHT + data->scale))
			{
				fdf_put_pixel(data, current.color, data->img.str + \
						((long)(current.y)*(long)data->img.size_line) + \
						((long)(current.x)*(long)(data->img.bpp / 8)));
				if (x > 0)
					fdf_bresenham(data, data->mapctr.map[x - 1][y], current);
				if (y > 0)
					fdf_bresenham(data, data->mapctr.map[x][y - 1], current);
			}
			x++;
		}
		y++;
	}
	return (1);
}
