/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:08:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/29 19:32:18 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;

	color = 0;
	color += blue;
	color += (green * 256);
	color += (red * 256 * 256);
	return (color);
}

unsigned char	red_color(int color)
{
	int	red;

	red = 0;
	while (color >= (256 * 256))
	{
		red++;
		color -= (256 * 256);
	}
	return (red);
}

unsigned char	green_color(int color)
{
	int	green;

	while (color >= (256 * 256))
		color -= (256 * 256);
	green = 0;
	while (color >= 256)
	{
		green++;
		color -= 256;
	}
	return (green);
}

unsigned char	blue_color(int color)
{
	int	blue;

	while (color >= (256 * 256))
		color -= (256 * 256);
	while (color >= 256)
		color -= 256;
	blue = color;
	return (blue);
}

t_color	*rrgb(int color)
{
	t_color	*elem;

	elem = malloc(sizeof(t_color));
	if (!elem)
		return (NULL);
	elem->red = red_color(color);
	elem->green = green_color(color);
	elem->blue = blue_color(color);
	return (elem);
}
