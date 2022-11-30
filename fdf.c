/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:55:20 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 03:09:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialisation(void **mlx_ptr, void **win_ptr, t_mlximg *img)
{
	*mlx_ptr = mlx_init();
	*win_ptr = mlx_new_window(*mlx_ptr, 500, 500, "42");
	img->ptr = mlx_new_image(mlx_ptr, 500, 500);
	img->buffer = mlx_get_data_addr(img->ptr, \
	&(img->bpp), &(img->sl), &(img->e));
}

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlximg	img;
	t_color		*color;
	size_t		x;
	size_t		y;

	initialisation(&mlx_ptr, &win_ptr, &img);
	color = new_tcolor(PURPLE);
	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			if (img.e == 0)
			{
				(img.buffer)[(y * img.sl) + (x * 4) + 3] = 0;
				(img.buffer)[(y * img.sl) + (x * 4) + 2] = red_color(color->value);
				(img.buffer)[(y * img.sl) + (x * 4) + 1] = green_color(color->value);
				(img.buffer)[(y * img.sl) + (x * 4) + 0] = blue_color(color->value);
			}
			else if (img.e == 1)
			{
				(img.buffer)[(y * img.sl) + (x * 4) + 0] = 0;
				(img.buffer)[(y * img.sl) + (x * 4) + 1] = red_color(color->value);
				(img.buffer)[(y * img.sl) + (x * 4) + 2] = green_color(color->value);
				(img.buffer)[(y * img.sl) + (x * 4) + 3] = blue_color(color->value);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
