/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:59:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/26 15:26:35 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clear_img(t_mlx *data)
{
	if (data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = mlx_new_image(data->ptr, \
			WIN_WIDTH, WIN_HEIGHT);
	data->img.str = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bpp), &(data->img.size_line), \
			&(data->img.endian));
}
