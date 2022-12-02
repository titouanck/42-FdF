/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_defscale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:13:57 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/02 16:24:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fdf_defscale(int width, int height)
{
	float	scale_w;
	float	scale_h;

	scale_w = (float)(SCREEN_W * SCREEN_POURCENT) / (float)width / PX_RPR;
	scale_h = (float)(SCREEN_H * SCREEN_POURCENT) / (float)height / PX_RPR;
	if (scale_w < scale_h)
		return (scale_w);
	else
		return (scale_h);
}