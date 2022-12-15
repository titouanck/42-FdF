/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorgradient_indice.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:51:13 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 15:51:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	fdf_colorgradient_indice(t_mlx *data, int x, int y)
{
	long	range;
	long	max;
	long	point;
	long	indice;

	range = data->mapctr.range;
	max = data->mapctr.max;
	point = (data->mapctr.map[x][y].z);
	indice = ((range - (max - point)) * data->nbrcolors) / range;
	return (indice);
}