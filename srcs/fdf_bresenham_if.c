/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:10:48 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/26 15:14:25 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_bresenham_if_while_color(t_point s, t_point e, t_bresenham vr)
{
	if (s.x < e.x)
		vr.current.color = rgb(((vr.scl.r * (1 - (vr.current.x - s.x) / \
	vr.diff)) + (vr.ecl.r * (((vr.current.x - s.x) / vr.diff)))), ((vr.scl.g \
	* (1 - (vr.current.x - s.x) / vr.diff)) + (vr.ecl.g * (((vr.current.x - \
	s.x) / vr.diff)))), ((vr.scl.b * (1 - (vr.current.x - s.x) / vr.diff)) \
	+ (vr.ecl.b * (((vr.current.x - s.x) / vr.diff)))));
	else
		vr.current.color = rgb(((vr.scl.r * ((vr.current.x - e.x) / vr.diff)) \
	+ (vr.ecl.r * (1 - ((vr.current.x - e.x) / vr.diff)))), ((vr.scl.g * \
	((vr.current.x - e.x) / vr.diff)) + (vr.ecl.g * (1 - ((vr.current.x - \
	e.x) / vr.diff)))), ((vr.scl.b * ((vr.current.x - e.x) / vr.diff)) + \
	(vr.ecl.b * (1 - ((vr.current.x - e.x) / vr.diff)))));
}

static void	fdf_bresenham_if_while(t_mlx *data, \
		t_point s, t_point e, t_bresenham vr)
{
	while ((int)(vr.current.x + 0.5) != (int)(e.x + 0.5))
	{
		fdf_bresenham_if_while_color(s, e, vr);
		if (vr.current.x < e.x)
			vr.current.x += 1;
		else
			vr.current.x -= 1;
		if (vr.current.y < e.y)
			vr.current.y = s.y + (vr.ratio * vr.i);
		else
			vr.current.y = s.y - (vr.ratio * vr.i);
		(vr.i)++;
		if (vr.current.x >= 0 && vr.current.x < WIN_WIDTH \
					&& vr.current.y >= 0 && vr.current.y < WIN_HEIGHT)
			fdf_call_put_pixel(data, vr.current);
	}	
}

void	fdf_bresenham_if(t_mlx *data, \
		t_point s, t_point e, float ratio)
{
	t_bresenham	vr;

	if ((s.x < 0 || s.x >= WIN_WIDTH || s.y < 0 \
	|| s.y >= WIN_HEIGHT) && (e.x < 0 || e.x >= WIN_WIDTH \
	|| e.y < 0 || e.y >= WIN_HEIGHT))
		return ;
	vr.scl = rrgb(s.color);
	vr.ecl = rrgb(e.color);
	vr.diff = fabs(e.x - s.x);
	vr.current = s;
	vr.ratio = ratio;
	vr.i = 0;
	fdf_bresenham_if_while(data, s, e, vr);
}
