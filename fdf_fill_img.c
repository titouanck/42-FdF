/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:22 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/05 18:57:03 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_put_pixel(t_mlx *mlxdata, int color, char *pixel)
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

int	fdf_fill_img(t_mlx *mlxdata, float scale)
{
	int		x;
	int		y;
	int		*colors;
	int		color;
	size_t	i;

	colors = fdf_colorgradient();
	if (!colors)
		return (ft_printf(ERR_ALLOC, 0));
	y = 0;
	while (y / scale < mlxdata->mapctr.height)
	{
		x = 0;
		while (x / scale < mlxdata->mapctr.width)
		{
			// i = 0;
			// while (i < scale)
			// {
				color = colors[(mlxdata->mapctr.range - \
						(int)(mlxdata->mapctr.max - (mlxdata->mapctr.map) \
						[(int)roundf(x / scale)][(int)roundf(y / scale)])) \
						* 510 / mlxdata->mapctr.range];
				fdf_put_pixel(mlxdata, color, mlxdata->img.str + \
						(y * mlxdata->img.size_line) + \
						(x * (mlxdata->img.bpp / 8)));
			// 	i++;
			// }
			x++;
		}
		y++;
	}
	return (1);
}
