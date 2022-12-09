/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:01:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 12:07:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_put_pixel(t_mlx *data, int color, char *pixel)
{
	t_color	tcolor;

	if (pixel < data->img.str || pixel >= (data->img.str + \
			((WIN_HEIGHT - 1) * data->img.size_line) + \
			((WIN_WIDTH - 1) * (data->img.bpp / 8))))
		return (0);
	tcolor = rrgb(color);
	if (data->img.endian == 1)
	{
		*(pixel + 0) = 0;
		*(pixel + 1) = tcolor.r;
		*(pixel + 2) = tcolor.g;
		*(pixel + 3) = tcolor.b;
	}
	else if (data->img.endian == 0)
	{
		*(pixel + 3) = 0;
		*(pixel + 2) = tcolor.r;
		*(pixel + 1) = tcolor.g;
		*(pixel + 0) = tcolor.b;
	}
	else
		return (0);
	return (1);
}
