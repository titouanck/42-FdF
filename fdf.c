/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 21:32:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clear_img(t_mlx *data, t_mapctr *mapctr)
{
	long	x;
	long	y;
	t_point	current;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = data->mapctr.map[x][y];
			fdf_put_pixel(data, BLACK, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
			if (x > 0)
				fdf_clearlines(data, data->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_clearlines(data, data->mapctr.map[x][y - 1], current);
		}
	}
}

int	fdf_zoom(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	printf("scale = %p | key : %d\n", param, key);
	if (key == 65362 && data->scale < WIN_WIDTH)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale)++;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, 45, 1, 0.5);
	}
	else if (key == 65364 && data->scale > 1)
	{
		fdf_clear_img(data, &(data->mapctr));
		(data->scale)--;
		mlx_clear_window(data->ptr, data->win);
		fdf_map_to_screen(data, 45, 1, 0.5);
	}
}

// int	fdf_rotate(int key, void *param)
// {
// 	t_mlx	*data;

// 	data = (t_mlx *)param;
// 	printf("scale = %p | key : %d\n", param, key);
// 	if (key == 65361 && data->scale < WIN_WIDTH)
// 	{
// 		fdf_clear_img(data, &(data->mapctr));
// 		mlx_clear_window(data->ptr, data->win);
// 		fdf_map_to_screen(data, 45, 1, 0.5);
// 	}
// 	else if (key == 65363 && data->scale > 1)
// 	{
// 		fdf_clear_img(data, &(data->mapctr));
// 		mlx_clear_window(data->ptr, data->win);
// 		fdf_map_to_screen(data, 45, 1, 0.5);
// 	}
// }

int	fdf(char *file)
{
	t_mlx	mlxdata;

	if (!file)
		return (0);
	mlxdata.ptr = mlx_init();
	if (fdf_fileoperations(file, &mlxdata))
	{
		mlxdata.win = mlx_new_window(mlxdata.ptr, \
				WIN_WIDTH, \
				WIN_HEIGHT, "FdF");
		mlxdata.colors = fdf_colorgradient();
		if (!(mlxdata.colors))
			return (ft_printf(ERR_ALLOC), 0);
		fdf_colormap(&mlxdata, mlxdata.colors);
		mlxdata.scale = 50;
		fdf_map_to_screen(&mlxdata, 45, 1, 0.5);
		mlx_key_hook(mlxdata.win, (* fdf_zoom), &mlxdata);
		mlx_loop(mlxdata.ptr);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc < 2)
			ft_printf("FdF: missing file operand\n");
		else
			ft_printf("FdF: too many file operands\n");
		ft_printf("Usage: ./FdF [FILE]\n");
		return (1);
	}
	if (!fdf(argv[1]))
		return (ft_printf("Error occurred for argument \"%s\"\n", argv[1]), 1);
	return (0);
}
