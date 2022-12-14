/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:05:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/14 03:07:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	if ((start.x < 0 || start.x >= WIN_WIDTH || start.y < 0 || start.y >= WIN_HEIGHT) && (end.x < 0 || end.x >= WIN_WIDTH || end.y < 0 || end.y >= WIN_HEIGHT))
		return ;
	startcolor = rrgb(start.color);
	endcolor = rrgb(end.color);
	diff = fabs(end.x - start.x);
	current = start;
	i = 0;
	while ((int)(current.x + 0.5) != (int)(end.x + 0.5))
	{
		if (start.x < end.x)
			current.color = rgb(((startcolor.r * (1 - (current.x - start.x) / diff)) + (endcolor.r * (((current.x - start.x) / diff)))), ((startcolor.g * (1 - (current.x - start.x) / diff)) + (endcolor.g * (((current.x - start.x) / diff)))), ((startcolor.b * (1 - (current.x - start.x) / diff)) + (endcolor.b * (((current.x - start.x) / diff)))));
		else
			current.color = rgb(((startcolor.r * ((current.x - end.x) / diff)) + (endcolor.r * (1 - ((current.x - end.x) / diff)))), ((startcolor.g * ((current.x - end.x) / diff)) + (endcolor.g * (1 - ((current.x - end.x) / diff)))), ((startcolor.b * ((current.x - end.x) / diff)) + (endcolor.b * (1 - ((current.x - end.x) / diff)))));
		if (current.x < end.x)
			current.x += 1;
		else
			current.x -= 1;
		if (current.y < end.y)
			current.y = start.y + (ratio * i);
		else
			current.y = start.y - (ratio * i);
		i++;
		if (current.x >= 0 && current.x < WIN_WIDTH \
					&& current.y >= 0 && current.y < WIN_HEIGHT)
			fdf_call_put_pixel(data, current);
	}
}

static void	fdf_bresenham_else(t_mlx *data, \
		t_point start, t_point end, float ratio)
{
	if ((start.x < 0 || start.x >= WIN_WIDTH || start.y < 0 || start.y >= WIN_HEIGHT) && (end.x < 0 || end.x >= WIN_WIDTH || end.y < 0 || end.y >= WIN_HEIGHT))
		return ;
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
	while ((int)(current.y + 0.5) != (int)(end.y + 0.5))
	{
		if (start.y < end.y)
			current.color = rgb(((startcolor.r * (1 - (current.y - start.y) / diff)) + (endcolor.r * (((current.y - start.y) / diff)))), ((startcolor.g * (1 - (current.y - start.y) / diff)) + (endcolor.g * (((current.y - start.y) / diff)))), ((startcolor.b * (1 - (current.y - start.y) / diff)) + (endcolor.b * (((current.y - start.y) / diff)))));
		else
			current.color = rgb(((startcolor.r * ((current.y - end.y) / diff)) + (endcolor.r * (1 - ((current.y - end.y) / diff)))), ((startcolor.g * ((current.y - end.y) / diff)) + (endcolor.g * (1 - ((current.y - end.y) / diff)))), ((startcolor.b * ((current.y - end.y) / diff)) + (endcolor.b * (1 - ((current.y - end.y) / diff)))));
		if (current.y < end.y)
			current.y += 1;
		else
			current.y -= 1;
		if (current.x < end.x)
			current.x = start.x + (ratio * i);
		else
			current.x = start.x - (ratio * i);
		i++;
		if (current.x >= 0 && current.x < WIN_WIDTH \
					&& current.y >= 0 && current.y < WIN_HEIGHT)
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
