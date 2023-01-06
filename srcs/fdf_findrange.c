/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_findrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:40:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/06 11:32:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_findrangee(t_mapctr *mapctr)
{
	long	x;
	long	y;
	int		current;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = ((mapctr->map)[x][y]).z;
			if (current < mapctr->min)
				mapctr->min = current;
			if (current > mapctr->max)
				mapctr->max = current;
		}
	}
	if (mapctr->min < 0)
	{
		if ((-(mapctr->min)) > mapctr->max)
			mapctr->max = (-(mapctr->min));
		else
			mapctr->min = (-(mapctr->max));
	}
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
}

void	fdf_findrange(t_mapctr *mapctr)
{
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)
		mapctr->range = 1;
}
