/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/06 20:13:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_bresenham_if(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	size_t	i;

	current = start;
	i = 0;
	while (current.x != end.x)
	{
		if (current.x < end.x)
			current.x += 1;
		else
			current.x -= 1;
		if (current.y < end.y)
			current.y = start.y + (ratio * i);
		else
			current.y = start.y - (ratio * i);
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
	size_t	i;

	current = start;
	i = 0;
	while (current.y != end.y)
	{
		if (current.y < end.y)
			current.y += 1;
		else
			current.y -= 1;
		if (current.x < end.x)
			current.x = start.x + (ratio * i);
		else
			current.x = start.x - (ratio * i);
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
	yrange = end.y - start.y;
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
