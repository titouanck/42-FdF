/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:50:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/05 17:52:18 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_print_map(t_mapctr mapctr)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < mapctr.height)
	{
		x = 0;
		while (x < mapctr.width)
		{
			printf("%-3d", (mapctr.map)[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
}
