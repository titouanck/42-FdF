/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:58:18 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/06 06:47:35 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_parallel(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (WIN_WIDTH <= WIN_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (WIN_WIDTH <= WIN_HEIGHT)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (WIN_WIDTH > WIN_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 135;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_flat(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (WIN_WIDTH <= WIN_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (WIN_WIDTH <= WIN_HEIGHT)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (WIN_WIDTH > WIN_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 45;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_default(void *param)
{
	t_mlx	*dt;

	dt = (t_mlx *)param;
	fdf_clear_img(dt);
	if (WIN_WIDTH <= WIN_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
	else if (WIN_WIDTH <= WIN_HEIGHT)
		dt->scale = WIN_WIDTH / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	else if (WIN_WIDTH > WIN_HEIGHT && dt->mapctr.width > \
	dt->mapctr.height)
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
	else
		dt->scale = WIN_HEIGHT / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	dt->deg = 45;
	dt->iy = 80;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_changecolor(t_mlx *dt)
{
	if (dt->colors)
		free(dt->colors);
	else
		return (0);
	fdf_clear_img(dt);
	dt->colors = NULL;
	dt->gradient += 1;
	dt->colors = fdf_colorgradient(dt);
	fdf_empty_colormap(dt, dt->colors);
	fdf_colormap(dt, dt->colors);
	fdf_map_to_screen(dt);
	return (1);
}
