/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colored_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:20:35 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/29 23:25:45 by tchevrie         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf("Imbecile", 0));
	ft_colored_window(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
