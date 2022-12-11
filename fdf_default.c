/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:58:18 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/11 17:57:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_default(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	data->scale = 35;
	data->deg = 45;
	data->ix = 1;
	data->iy = 0.5;
	data->mapctr.translatex = 0;
	data->mapctr.translatey = 0;
	data->relief = hypotf(data->mapctr.width, data->mapctr.width) / 15;
	fdf_map_to_screen(data);
	return (1);
}
