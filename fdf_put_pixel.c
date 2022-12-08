/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:01:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 18:12:46 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_put_pixel(t_mlx *mlxdata, int color, char *pixel)
{
	t_color	tcolor;

	tcolor = rrgb(color);
	if (mlxdata->img.endian == 1)
	{
		*(pixel + 0) = 0;
		*(pixel + 1) = tcolor.r;
		*(pixel + 2) = tcolor.g;
		*(pixel + 3) = tcolor.b;
	}
	else if (mlxdata->img.endian == 0)
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
