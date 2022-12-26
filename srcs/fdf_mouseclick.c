/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouseclick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:12:07 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 14:42:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_rotate(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_SCROLLLEFT)
		(data->deg)++;
	else if (key == KV_SCROLLRIGHT)
		(data->deg)--;
	fdf_map_to_screen(data);
	return (1);
}

static int	fdf_zoom(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if ((key == KV_SCROLLUP) && data->scale < (WIN_WIDTH / 2))
		(data->scale) *= 1.05;
	else if ((key == KV_SCROLLDOWN) && data->scale > 0.05)
		(data->scale) /= 1.05;
	fdf_map_to_screen(data);
	return (1);
}

int	fdf_mouseclick(int key, int x, int y, void *param)
{
	t_mlx	*data;

	(void)x;
	(void)y;
	data = (t_mlx *)param;
	if (key == KV_SCROLLUP || key == KV_SCROLLDOWN)
		fdf_zoom(key, data);
	if (key == KV_SCROLLLEFT || key == KV_SCROLLRIGHT)
		fdf_rotate(key, data);
	return (1);
}
