/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_findrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:40:40 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/05 18:02:34 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_findrange(t_mapctr *mapctr)
{
	size_t	x;
	size_t	y;
	int		current;

	mapctr->min = 2147483647;
	mapctr->max = -2147483648;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = (mapctr->map)[x][y];
			if (current < mapctr->min)
				mapctr->min = current;
			if (current > mapctr->max)
				mapctr->max = current;
		}
	}
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
}
