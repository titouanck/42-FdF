/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 14:37:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	fdf_colorgradient_z(t_mlx *mlxdata, float point)
{
	float	colors;
	float	range;
	float	max;
	float	indice;

	colors = 510;
	range = mlxdata->mapctr.range;
	max = mlxdata->mapctr.max;
	indice = ((range - (max - point)) * colors) / range;
	return (roundf(indice));
}

static void	fdf_bresenham_if(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	zratio;
	float	i;

	// steps = end.x - start.x;
	zratio = end.z - start.z;
	if (fabs(start.x - end.x) != 0)
		zratio = zratio / fabs(start.x - end.x);
	current = start;
	i = 0;
	while (roundf(current.x) != roundf(end.x))
	{
		if (current.x < end.x)
			current.x += 1;
		else
			current.x -= 1;
		if (current.y < end.y)
			current.y = start.y + (ratio * i);
		else
			current.y = start.y - (ratio * i);
		if (zratio < 0)
			current.z = start.z - (fabs(zratio) * i);
		else
			current.z = start.z + (fabs(zratio) * i);
		current.color = data->colors[fdf_colorgradient_z(data, current.z)];
		fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
		i++;
	}
}

static void	fdf_bresenham_else(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	zratio;
	float	i;

	zratio = end.z - start.z;
	if (fabs(start.y - end.y) != 0)
		zratio = zratio / fabs(end.y - start.y);
	current = start;
	i = 0;
	while (roundf(current.y) != roundf(end.y))
	{
		if (current.y < end.y)
			current.y += 1;
		else
			current.y -= 1;
		if (current.x < end.x)
			current.x = start.x + (ratio * i);
		else
			current.x = start.x - (ratio * i);
		if (zratio < 0)
			current.z = start.z - (fabs(zratio) * i);
		else
			current.z = start.z + (fabs(zratio) * i);
		current.color = data->colors[fdf_colorgradient_z(data, current.z)];
		fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
		i++;
	}
}

void	fdf_bresenham(t_mlx *data, t_point start, t_point end)
{
	float	xrange;
	float	yrange;
	float	ratio;

	xrange = end.x - start.x;
	if (xrange < 0)
		xrange = xrange * -1;
	yrange = end.y - start.y;
	if (yrange < 0)
		yrange = yrange * -1;
	xrange = ((int)(xrange * 100)) / 100;
	yrange = ((int)(yrange * 100)) / 100;
	if (xrange > yrange)
	{
		ratio = yrange / xrange;
		fdf_bresenham_if(data, start, end, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		fdf_bresenham_else(data, start, end, ratio);
	}
}
