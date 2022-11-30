/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lstmap_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:45:23 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 22:18:09 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*fdf_lstmap_new(void *mlx_ptr, int fd)
{
	t_map	*elem;

	elem = malloc(sizeof(t_map));
	if (!elem)
		return (NULL);
	fdf_mapsize(fd, &(elem->width), &(elem->height));
	if (elem->width <= 0 || elem->height <= 0)
		return (free(elem), NULL);
	elem->img = mlx_new_image(mlx_ptr, elem->width, elem->height);
	return (elem);
}
