/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:10 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

void	fdf_bresenham(t_mlx *data, t_point s, t_point e)
{
	float	xrange;
	float	yrange;
	float	ratio;

	xrange = e.x - s.x;
	if (xrange < 0)
		xrange = xrange * -1;
	yrange = e.y - s.y;
	if (yrange < 0)
		yrange = yrange * -1;
	if (xrange > yrange)
	{
		ratio = yrange / xrange;
		fdf_bresenham_if(data, s, e, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		fdf_bresenham_else(data, s, e, ratio);
	}
}
