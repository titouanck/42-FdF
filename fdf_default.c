/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:58:18 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/26 15:15:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_default(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if (WIN_WIDTH <= WIN_HEIGHT && data->mapctr.width > data->mapctr.height)
		data->scale = WIN_WIDTH / hypotf(data->mapctr.width, \
	data->mapctr.width);
	else if (WIN_WIDTH <= WIN_HEIGHT)
		data->scale = WIN_WIDTH / hypotf(data->mapctr.height, \
	data->mapctr.height);
	else if (WIN_WIDTH > WIN_HEIGHT && data->mapctr.width > \
	data->mapctr.height)
		data->scale = WIN_HEIGHT / hypotf(data->mapctr.width, \
	data->mapctr.width);
	else
		data->scale = WIN_HEIGHT / hypotf(data->mapctr.height, \
	data->mapctr.height);
	data->deg = 45;
	data->iy = 80;
	data->mapctr.translatex = 0;
	data->mapctr.translatey = 0;
	data->relief = hypotf(data->mapctr.width, data->mapctr.width) / 15;
	fdf_map_to_screen(data);
	return (1);
}
