/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:57:05 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 23:55:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_map_rotation(t_mapctr *mapctr, float deg)
{
	long	x;
	long	y;
	float	old_x;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			old_x = ((mapctr->map)[x][y]).x;
			((mapctr->map)[x][y]).x = old_x * \
					cos(deg / 57.2958) + ((mapctr->map)[x][y]).y * \
					(sin(deg / 57.2958) * -1) + mapctr->translatex;
			((mapctr->map)[x][y]).y = old_x * \
					sin(deg / 57.2958) + ((mapctr->map)[x][y]).y * \
					cos(deg / 57.2958) + mapctr->translatey;
		}
	}
}

static void	fdf_map_inclinaison(t_mapctr *mapctr, float ix, float iy)
{
	long	x;
	long	y;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x *= ix;
			((mapctr->map)[x][y]).y *= iy;
		}
	}
}

static void	fdf_map_center(t_mapctr *mapctr)
{
	long	x;
	long	y;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x += WIN_WIDTH / 2;
			((mapctr->map)[x][y]).y += WIN_HEIGHT / 2;
		}
	}
}

static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	in_range;

	if (data->mapctr.range == 0)
		return ;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			in_range = ((((float)mapctr->range - \
				((float)mapctr->max - (float)(mapctr->map[x][y].z))) \
					/ (float)mapctr->range) * data->relief) * \
						((hypot(data->scale, data->scale)) / 2);
			((mapctr->map)[x][y]).y -= in_range * (1 - fabs(data->iy));
			((mapctr->map)[x][y]).x -= in_range * (1 - fabs(data->ix));
		}
	}
}

void	fdf_map_fill(t_mlx *data)
{
	fdf_map_fill_xy(&(data->mapctr), data->scale);
	fdf_map_rotation(&(data->mapctr), data->deg);
	fdf_map_inclinaison(&(data->mapctr), data->ix, data->iy);
	fdf_map_relief(&(data->mapctr), data);
	fdf_map_center(&(data->mapctr));
}
