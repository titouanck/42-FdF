/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:20:35 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/29 21:09:11 by tchevrie         ###   ########.fr       */
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

	w = 255 * (w / 255);
	h = 255 * (h / 255);
	if (w < 255)
		w = 255;
	if (h < 255)
		h = 255;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, "42");
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			color = rgb(x / (w / 255), y / (h / 255), 255 - x / (w / 255));
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		}
	}
	mlx_loop(mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf("Imbecile", 0));
	ft_colored_window(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
