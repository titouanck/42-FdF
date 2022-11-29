/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:20:35 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/29 19:31:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	int		color;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;

	color = rgb(17, 127, 122);
	ft_printf("La couleur vaut %x\n", color);
	// width = 750;
	// height = 750;
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, width, height, "42");
	// while (width > 0 && height > 0)
	// {
	// 	mlx_pixel_put(mlx_ptr, win_ptr, width, height, color);
	// 	color++;
	// 	width--;
	// 	height--;
	// }
	rrgb(color);
	// mlx_loop(mlx_ptr);
}
