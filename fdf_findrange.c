/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_findrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:40:40 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 17:23:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_findrange(t_mapctr *mapctr)
{
	long	x;
	long	y;
	int		current;

	mapctr->min = 2147483647;
	mapctr->max = -2147483648;
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
