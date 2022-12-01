/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lstmap_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:45:23 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 15:21:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*fdf_lstmap_new(void *mlx_ptr, int fd)
{
	t_map	*elem;
	int		*bpp;
	int		*size_line;
	int		*endian;

	elem = malloc(sizeof(t_map));
	if (!elem)
		return (NULL);
	fdf_mapsize(fd, &(elem->width), &(elem->height));
	if (elem->width <= 0 || elem->height <= 0)
		return (free(elem), NULL);
	elem->img = mlx_new_image \
		(mlx_ptr, elem->width * SCALE, elem->height * SCALE);
	bpp = &(elem->bpp);
	size_line = &(elem->size_line);
	endian = &(elem->endian);
	elem->buf = mlx_get_data_addr(elem->img, bpp, size_line, endian);
	return (elem);
}
