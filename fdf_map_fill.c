/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:57:05 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 13:32:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Rotation classique -> inclinaison y -> inclinaison x -> center map */
static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	old_x;
	t_point	*cur;

	mapctr->xorigin = (((float)mapctr->width - 1.0) / 2) * data->scale;
	mapctr->yorigin = (((float)mapctr->height - 1.0) / 2) * data->scale;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			cur = &((mapctr->map)[x][y]);
			cur->x = x * data->scale - mapctr->xorigin;
			cur->y = y * data->scale - mapctr->yorigin;
			old_x = cur->x;
			cur->x = old_x * data->deg_cos + cur->y * (-(data->deg_sin));
			cur->y = old_x * data->deg_sin + cur->y * data->deg_cos;
			cur->y = cur->y * data->iy_sin + cur->y * data->iy_cos + \
					WIN_HEIGHT / 2 + mapctr->translatey;
			cur->x = cur->x * 1.41421356237 + WIN_WIDTH / 2 + \
					mapctr->translatex;
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
			((mapctr->map)[x][y]).y -= in_range * (-(data->iy_cos)) + in_range * (data->iy_sin);
		}
	}
}

void	fdf_map_fill(t_mlx *data)
{
	data->deg_sin = sin(data->deg / RAD);
	data->deg_cos = cos(data->deg / RAD);
	data->iy_sin = sin(data->iy / RAD);
	data->iy_cos = cos(data->iy / RAD);
	fdf_map_rotation(&(data->mapctr), data);
	fdf_map_relief(&(data->mapctr), data);
}
