/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/11 17:43:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	fdf_colorgradient_z(t_mlx *data, float point)
{
	float	colors;
	float	range;
	float	max;
	float	indice;

	range = data->mapctr.range;
	max = data->mapctr.max;
	indice = ((range - (max - point)) * data->nbrcolors) / range;
	return (roundf(indice));
}

static void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

static void	fdf_bresenham_if(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	diff;
	float	i;
	t_color	startcolor;
	t_color	endcolor;

	startcolor = rrgb(start.color);
	endcolor = rrgb(end.color);
	diff = fabs(end.x - start.x);
	current = start;
	i = 0;
	while (roundf(current.x) != roundf(end.x))
	{
		if (start.x < end.x)
		{
			// current.color = ((start.color * (1 - (current.x - start.x) / diff)) + (end.color * (((current.x - start.x) / diff))));	
			// current.color = ((startcolor.r * (1 - (current.x - start.x) / diff)) + (endcolor.r * (((current.x - start.x) / diff))));	
			current.color = rgb(((startcolor.r * (1 - (current.x - start.x) / diff)) + (endcolor.r * (((current.x - start.x) / diff)))), ((startcolor.g * (1 - (current.x - start.x) / diff)) + (endcolor.g * (((current.x - start.x) / diff)))), ((startcolor.b * (1 - (current.x - start.x) / diff)) + (endcolor.b * (((current.x - start.x) / diff)))));
		}
		else
		{
			current.color = ((start.color * ((current.x - end.x) / diff)) + (end.color * (1 - ((current.x - end.x) / diff))));	
			current.color = rgb(((startcolor.r * ((current.x - end.x) / diff)) + (endcolor.r * (1 - ((current.x - end.x) / diff)))), ((startcolor.g * ((current.x - end.x) / diff)) + (endcolor.g * (1 - ((current.x - end.x) / diff)))), ((startcolor.b * ((current.x - end.x) / diff)) + (endcolor.b * (1 - ((current.x - end.x) / diff)))));
		}
		if (current.x < end.x)
			current.x += 1;
		else
			current.x -= 1;
		if (current.y < end.y)
			current.y = start.y + (ratio * i);
		else
			current.y = start.y - (ratio * i);
		i++;
		fdf_call_put_pixel(data, current);
	}
}

static void	fdf_bresenham_else(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	t_point	current;
	float	diff;
	float	i;
	t_color	startcolor;
	t_color	endcolor;

	startcolor = rrgb(start.color);
	endcolor = rrgb(end.color);

	diff = fabs(start.y - end.y);
	current = start;
	i = 0;
	while (roundf(current.y) != roundf(end.y))
	{
		if (start.y < end.y)
			current.color = rgb(((startcolor.r * (1 - (current.y - start.y) / diff)) + (endcolor.r * (((current.y - start.y) / diff)))), ((startcolor.g * (1 - (current.y - start.y) / diff)) + (endcolor.g * (((current.y - start.y) / diff)))), ((startcolor.b * (1 - (current.y - start.y) / diff)) + (endcolor.b * (((current.y - start.y) / diff)))));
			// current.color = ((start.color * (1 - (current.y - start.y) / diff)) + (end.color * (((current.y - start.y) / diff))));	
		else
			current.color = rgb(((startcolor.r * ((current.y - end.y) / diff)) + (endcolor.r * (1 - ((current.y - end.y) / diff)))), ((startcolor.g * ((current.y - end.y) / diff)) + (endcolor.g * (1 - ((current.y - end.y) / diff)))), ((startcolor.b * ((current.y - end.y) / diff)) + (endcolor.b * (1 - ((current.y - end.y) / diff)))));
			// current.color = ((start.color * ((current.y - end.y) / diff)) + (end.color * (1 - ((current.y - end.y) / diff))));	
		if (current.y < end.y)
			current.y += 1;
		else
			current.y -= 1;
		if (current.x < end.x)
			current.x = start.x + (ratio * i);
		else
			current.x = start.x - (ratio * i);
		i++;
		fdf_call_put_pixel(data, current);
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
