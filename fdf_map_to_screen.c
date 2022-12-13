/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:11 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/13 17:18:13 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_map_to_screen(t_mlx *data)
{
	fdf_map_fill(data);
	fdf_fill_img(data);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	printf("fdf_map_to_screen() -> OK!\n\n");
	return (1);
}
