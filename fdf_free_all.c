/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:38:31 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/10 00:52:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_free_map(t_point **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

int	fdf_free_all(t_mlx *data)
{
	if (data->ptr && data->win)
		mlx_destroy_window(data->ptr, data->win);
	data->win = NULL;
	if (data->ptr && data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = NULL;
	if (data->ptr)
	{
		// mlx_destroy_display(data->ptr);
		free(data->ptr);
	}
	data->ptr = NULL;
	if (data->mapctr.map)
		fdf_free_map(data->mapctr.map);
	data->mapctr.map = NULL;
	if (data->colors)
		free(data->colors);
	data->colors = NULL;
	return (0);
}
