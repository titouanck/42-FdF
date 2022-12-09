/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:39:57 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/09 11:57:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fdf_get_scale(t_mlx *data)
{
	float	scalex;
	float	scaley;

	scalex = WIN_WIDTH / hypotf(data->mapctr.width, data->mapctr.height);
	scaley = WIN_HEIGHT / hypotf(data->mapctr.width, data->mapctr.height);
	if (scalex < scaley)
		return (scalex);
	else
		return (scaley);
}
