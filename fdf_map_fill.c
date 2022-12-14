/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:57:05 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/14 03:03:47 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Rotation classique -> inclinaison y -> inclinaison x -> center map */
static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	old_x;

	mapctr->xorigin = (((float)mapctr->width - 1.0) / 2) * data->scale;
	mapctr->yorigin = (((float)mapctr->height - 1.0) / 2) * data->scale;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x = x * data->scale - mapctr->xorigin;
			((mapctr->map)[x][y]).y = y * data->scale - mapctr->yorigin;
			old_x = ((mapctr->map)[x][y]).x;
			((mapctr->map)[x][y]).x = old_x * cos(data->deg / RAD) + \
	((mapctr->map)[x][y]).y * (sin(data->deg / RAD) * -1) + mapctr->translatex;
			((mapctr->map)[x][y]).y = old_x * sin(data->deg / RAD) + \
	((mapctr->map)[x][y]).y * cos(data->deg / RAD) + mapctr->translatey;
			((mapctr->map)[x][y]).y = ((mapctr->map)[x][y]).y * sin(data->iy \
	/ RAD) + ((mapctr->map)[x][y]).y * cos(data->iy / RAD) + WIN_HEIGHT / 2;
			((mapctr->map)[x][y]).x = ((mapctr->map)[x][y]).x * sin(data->ix \
	/ RAD) + ((mapctr->map)[x][y]).x * cos(data->ix / RAD) + WIN_WIDTH / 2;
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
			((mapctr->map)[x][y]).y -= in_range * -cos(data->iy / RAD) + in_range * (sin(data->iy / RAD));
			((mapctr->map)[x][y]).x -= in_range * -sin(data->ix / RAD) + in_range * cos(data->ix / RAD);
		}
	}
}

void	fdf_map_fill(t_mlx *data)
{
	fdf_map_rotation(&(data->mapctr), data);
	fdf_map_relief(&(data->mapctr), data);
}
