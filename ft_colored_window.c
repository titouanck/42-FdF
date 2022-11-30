/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colored_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:20:35 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 22:56:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_colored_window(int w, int h)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	size_t	x;
	size_t	y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, "42");
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			color = rgb(x / ((float)w / 255), \
			y / ((float)h / 255), \
			255 - x / ((float)w / 255));
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
}
