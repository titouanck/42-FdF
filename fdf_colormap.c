/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colormap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:50:43 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/06 20:14:29 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_colormap(t_mlx *mlxdata, int *colors)
{
	size_t	x;
	size_t	y;

	if (!colors)
	{
		ft_printf(ERR_ALLOC, 0);
		return ;
	}
	x = 0;
	while (x < mlxdata->mapctr.width)
	{
		y = 0;
		while (y < mlxdata->mapctr.height)
		{
			mlxdata->mapctr.map[x][y].color = \
					colors[fdf_colorgradient_indice(mlxdata, x, y)];
			y++;
		}
		x++;
	}
}