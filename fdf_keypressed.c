/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:44:30 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 11:38:28 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_clear_img(t_mlx *data, t_mapctr *mapctr)
{
	long	x;
	long	y;
	t_point	current;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = data->mapctr.map[x][y];
			fdf_put_pixel(data, BLACK, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
			if (x > 0)
				fdf_clearlines(data, data->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_clearlines(data, data->mapctr.map[x][y - 1], current);
		}
	}
}

int	fdf_default(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	fdf_clear_img(data, &(data->mapctr));
	data->scale = fdf_get_scale(data);
	data->deg = 45;
	data->ix = 1;
	data->iy = 0.5;
	fdf_map_to_screen(data, data->deg, data->ix, data->iy);
}

static int	fdf_zoom(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if ((key == 65362 || key == 126) && data->scale < WIN_WIDTH)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale)++;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, data->deg, data->ix, data->iy);
	}
	else if ((key == 65364 || key == 125) && data->scale > 1)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale)--;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, data->deg, data->ix, data->iy);
	}
	return (1);
}

static int	fdf_rotate(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if ((key == 65363 || key == 124) && data->scale < WIN_WIDTH)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->deg)++;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, data->deg, data->ix, data->iy);
	}
	else if ((key == 65361 || key == 123) && data->scale > 1)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->deg)--;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, data->deg, data->ix, data->iy);
	}
	return (1);
}

void	fdf_keypressed(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	printf("param = %p | key : %d\n", param, key);
	if (key == 65361 || key == 123 || key == 65363 || key == 124)
		fdf_rotate(key, data);
	else if (key == 65362 || key == 126 || key == 65364 || key == 125)
		fdf_zoom(key, data);
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
}