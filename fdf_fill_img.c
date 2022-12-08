/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:22 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 10:56:48 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_fill_img(t_mlx *mlxdata, float scale)
{
	int		x;
	int		y;
	t_point	current;

	y = 0;
	while (y < mlxdata->mapctr.height)
	{
		x = 0;
		while (x < mlxdata->mapctr.width)
		{
			current = mlxdata->mapctr.map[x][y];
			fdf_put_pixel(mlxdata, current.color, mlxdata->img.str + \
					((long)(current.y)*(long)mlxdata->img.size_line) + \
					((long)(current.x)*(long)(mlxdata->img.bpp / 8)));
			// if (x > 0)
			// 	printf("Difference : %.2f\n", current.x - mlxdata->mapctr.map[x - 1][y].x);
			if (x > 0)
				fdf_bresenham(mlxdata, mlxdata->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_bresenham(mlxdata, mlxdata->mapctr.map[x][y - 1], current);
			x++;
		}
		y++;
		// fdf_bresenham(mlxdata, mlxdata->mapctr.map[0][0], mlxdata->mapctr.map[0][mlxdata->mapctr.height - 1]);
		// fdf_bresenham(mlxdata, mlxdata->mapctr.map[0][0], mlxdata->mapctr.map[mlxdata->mapctr.width - 1][0]);
		// fdf_bresenham(mlxdata, mlxdata->mapctr.map[1][0], mlxdata->mapctr.map[0][0]);
		// fdf_bresenham(mlxdata, mlxdata->mapctr.map[0][0], mlxdata->mapctr.map[0][1]);
		// fdf_bresenham(mlxdata, mlxdata->mapctr.map[0][0], mlxdata->mapctr.map[0][1]);
	}
	return (1);
}
