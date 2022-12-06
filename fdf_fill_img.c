/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:22 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/06 20:15:45 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_fill_img(t_mlx *mlxdata, float scale)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < mlxdata->mapctr.height)
	{
		x = 0;
		while (x < mlxdata->mapctr.width)
		{
			color = mlxdata->mapctr.map[x][y].color;
			fdf_put_pixel(mlxdata, color, mlxdata->img.str + \
					((long)(y * scale)*(long)mlxdata->img.size_line) + \
					((long)(x * scale)*(long)(mlxdata->img.bpp / 8)));
			if (x > 0)
				fdf_bresenham(mlxdata, mlxdata->mapctr.map[x - 1][y] \
						, mlxdata->mapctr.map[x][y]);
			if (y > 0)
				fdf_bresenham(mlxdata, mlxdata->mapctr.map[x][y - 1], \
						mlxdata->mapctr.map[x][y]);
			x++;
		}
		y++;
	}
	return (1);
}
