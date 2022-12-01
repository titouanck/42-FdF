/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:08:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 15:17:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;

	color = 0;
	color += blue;
	color += (green * 256);
	color += (red * 256 * 256);
	return (color);
}

void	rrgb(int cl, char *r, char *g, char *b)
{
	*r = 0;
	*g = 0;
	*b = 0;
	while (cl >= (256 * 256))
	{
		(*r)++;
		cl -= (256 * 256);
	}
	while (cl >= 256)
	{
		(*g)++;
		cl -= 256;
	}
	*b = cl;
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
