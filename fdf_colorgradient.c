/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorgradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:31:17 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/06 15:18:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	fdf_colorgradient_indice(t_mlx *mlxdata, int x, int y)
{
	long	colors;
	long	range;
	long	max;
	long	point;
	long	indice;

	colors = 510;
	range = mlxdata->mapctr.range;
	max = mlxdata->mapctr.max;
	point = (mlxdata->mapctr.map[x][y].z);
	indice = ((range - (max - point)) * colors) / range;
	return (indice);
}

int	*fdf_colorgradient(void)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 * 2 + 1));
	if (!tab)
		return (NULL);
	color = 0xffffff;
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 510)
			break ;
		if (color > 0xffff00)
			color -= 0x000001;
		else
		{
			color += 0x000001;
			color -= 0x000100;
		}
		i++;
	}
	return (tab);
}