/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:44:30 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/14 12:51:11 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_rotate(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_RIGHTCHEVRON || key == KV_RIGHTCHEVRON_M)
		(data->deg)++;
	else if (key == KV_LEFTCHEVRON || key == KV_LEFTCHEVRON_M)
		(data->deg)--;
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_translate(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_W || key == KV_W_M)
		(data->mapctr.translatey) += (data->scale / 5);
	else if (key == KV_S || key == KV_S_M)
		(data->mapctr.translatey) -= (data->scale / 5);
	else if (key == KV_A || key == KV_A_M)
		(data->mapctr.translatex) += (data->scale / 5);
	else if (key == KV_D || key == KV_D_M)
		(data->mapctr.translatex) -= (data->scale / 5);
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_incline(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_TOPARROW || key == KV_TOPARROW_M)
			(data->iy) += 5;
	else if (key == KV_BOTTOMARROW || key == KV_BOTTOMARROW_M)
			(data->iy) -= 5;
	else if (key == KV_LEFTARROW || key == KV_LEFTARROW_M)
			(data->ix) -= 5;
	else if (key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
			(data->ix) += 5;
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_relief(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_PLUS2)
		data->relief += 0.25;
	else if (key == KV_MINUS || key == KV_MINUS_M || key == KV_MINUS2)
		data->relief -= 0.25;
	if (data->relief != 0 && data->relief > -0.13 && data->relief < 0.13)
		data->relief = 0;
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_changecolor(t_mlx *data)
{
	if (data->colors)
		free(data->colors);
	else
		return (0);
	fdf_clear_img(data);
	data->colors = NULL;
	data->gradient += 1;
	data->colors = fdf_colorgradient(data);
	fdf_empty_colormap(data, data->colors);
	fdf_colormap(data, data->colors);
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_flat(t_mlx *data)
{
	fdf_clear_img(data);
	if (WIN_WIDTH <= WIN_HEIGHT && data->mapctr.width > data->mapctr.height)
		data->scale = WIN_WIDTH / hypotf(data->mapctr.width, data->mapctr.width);
	else if (WIN_WIDTH <= WIN_HEIGHT)
		data->scale = WIN_WIDTH / hypotf(data->mapctr.height, data->mapctr.height);
	else if (WIN_WIDTH > WIN_HEIGHT && data->mapctr.width > data->mapctr.height)
		data->scale = WIN_HEIGHT / hypotf(data->mapctr.width, data->mapctr.width);
	else
		data->scale = WIN_HEIGHT / hypotf(data->mapctr.height, data->mapctr.height);
	data->deg = 0;
	data->ix = 45;
	data->iy = 45;
	data->mapctr.translatex = 0;
	data->mapctr.translatey = 0;
	data->relief = hypotf(data->mapctr.width, data->mapctr.width) / 15;
	fdf_map_to_screen(data);
	return (1);
}

int	fdf_keypressed(int key, void *param)
{
	t_mlx *data;

	printf("Key pressed: %d\n", key);
	data = (t_mlx *)param;
	if (key == KV_LEFTCHEVRON || key == KV_LEFTCHEVRON_M
			|| key == KV_RIGHTCHEVRON || key == KV_RIGHTCHEVRON_M)
		fdf_rotate(key, data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_MINUS
		|| key == KV_PLUS2 || key == KV_MINUS2  || key == KV_MINUS_M)
		fdf_relief(key, data);
	else if (key == KV_W || key == KV_W_M || key == KV_S || key == KV_S_M
		|| key == KV_A || key == KV_A_M || key == KV_D || key == KV_D_M)
		fdf_translate(key, data);
	else if (key == KV_TOPARROW || key == KV_TOPARROW_M
		|| key == KV_BOTTOMARROW|| key == KV_BOTTOMARROW_M
		|| key == KV_LEFTARROW || key == KV_LEFTARROW_M
		|| key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
		fdf_incline(key, data);
	else if (key == KV_C || key == KV_C_M)
		fdf_changecolor(data);
	else if (key == KV_R || key == KV_R_M)
	{
		fdf_clear_img(data);
		fdf_default(data);
	}
	else if (key == KV_SPACE || key == KV_SPACE_M)
		fdf_flat(data);
	else if (key == KV_ESCAPE || key == KV_ESCAPE_M)
		exit(fdf_free_all(data));
	return (1);
}
