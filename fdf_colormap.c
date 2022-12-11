/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colormap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:50:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/11 18:06:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_empty_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_printf(ERR_ALLOC, 0);
		return ;
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (data->mapctr.map[x][y].color)
				data->mapctr.map[x][y].color = 0;
			y++;
		}
		x++;
	}
}

void	fdf_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_printf(ERR_ALLOC, 0);
		return ;
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (!(data->mapctr.map[x][y].color))
				data->mapctr.map[x][y].color = \
						colors[fdf_colorgradient_indice(data, x, y)];
			y++;
		}
		x++;
	}
}
