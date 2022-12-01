/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lstmap_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:27 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 15:17:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_lstmap_free(void *mlx_ptr, t_map *map)
{
	if (!mlx_ptr || !map)
		return ;
	if (map->img)
		mlx_destroy_image(mlx_ptr, map->img);
	if (map->map)
		fdf_mapfree(map->map);
	free(mlx_ptr);
}
