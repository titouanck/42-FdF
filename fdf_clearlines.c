/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clearlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:03:09 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 12:08:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_clearlines_if(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	i;

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
		fdf_put_pixel(data, BLACK, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
		i++;
	}
}

static void	fdf_clearlines_else(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	i;

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
		fdf_put_pixel(data, BLACK, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
		i++;
	}
}

void	fdf_clearlines(t_mlx *data, t_point start, t_point end)
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
		fdf_clearlines_if(data, start, end, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		fdf_clearlines_else(data, start, end, ratio);
	}
}
