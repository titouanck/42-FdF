/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouseclick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:12:07 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 15:32:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_zoom(int key, t_mlx *data)
{
	if ((key == 4) && data->scale < (WIN_WIDTH / 2))
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale) *= 1.05;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data);
	}
	else if ((key == 5) && data->scale > 1)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale) /= 1.05;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data);
	}
	return (1);
}

int	fdf_mouseclick(int key, int x, int y, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	// printf("param = %p | key : %d\n", param, key);
	if (key == 4 || key == 5)
		fdf_zoom(key, data);
	return (1);
}
