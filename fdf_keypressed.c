/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:44:30 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 15:43:25 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_rotate(int key, t_mlx *data)
{
	if ((key == 65363 || key == 124) && data->scale < WIN_WIDTH)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->deg)++;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data);
	}
	else if ((key == 65361 || key == 123) && data->scale > 1)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->deg)--;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data);
	}
	return (1);
}

static int	fdf_translate(int key, t_mlx *data)
{
	if (key == 119)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->mapctr.translatey) += 10;
	}
	else if (key == 115)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->mapctr.translatey) -= 10;
	}
	else if (key == 97)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->mapctr.translatex) += 10;
	}
	else if (key == 100)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->mapctr.translatex) -= 10;
	}
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int fdf_incline(int key, t_mlx *data)
{
	if (key == 65362)
	{
		fdf_clear_img(data, &(data->mapctr));
		if (data->iy < 1)
			(data->iy) += 0.05;
	}
	else if (key == 65364)
	{
		fdf_clear_img(data, &(data->mapctr));
		if (data->iy > -1)
			(data->iy) -= 0.05;
	}
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

static int fdf_relief(int key, t_mlx *data)
{
	if (key == 61 || key == 65451)
	{
		fdf_clear_img(data, &(data->mapctr));
		data->relief += 0.05;
	}
	else if (key == 45 || key == 65453)
	{
		fdf_clear_img(data, &(data->mapctr));
		data->relief -= 0.05;
	}
	mlx_clear_window(data->ptr, data->win);
	fdf_map_to_screen(data);
	return (1);
}

int	fdf_keypressed(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	// printf("param = %p | key : %d\n", param, key);
	if (key == 65361 || key == 123 || key == 65363 || key == 124)
		fdf_rotate(key, data);
	else if (key == 61 || key == 45 || key == 65451 || key == 65453)
		fdf_relief(key, data);
	else if (key == 119 || key == 115 || key == 97 || key == 100)
		fdf_translate(key, data);
	else if (key == 65362 || key == 65364)
		fdf_incline(key, data);
	else if (key == 15 || key == 114)
	{
		fdf_clear_img(((t_mlx *)data), &(((t_mlx *)data)->mapctr));
		fdf_default(data);
	}
	else if (key == 65307)
	{
		fdf_free_all(data);
		exit(0);
	}
	return (1);
}
