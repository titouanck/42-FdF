/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:20:35 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/29 14:45:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	int x = 2500;
	int y = 1000;
	int color = 0x000000;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2500, 1000, "mlx 42");
	while (x)
	{
		while (y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			y--;
		}
		color++;

		y = 2500;
		x--;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
