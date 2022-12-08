/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 17:57:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_relief(t_mlx *mlxdata, t_mapctr *mapctr)
{
	long	x;
	long	y;
	float	angle;

	if (mapctr->range == 0)
		return ;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x -= ((((float)mapctr->range - ((float)mapctr->max - (float)(mapctr->map[x][y].z))) / (float)mapctr->range) * 0.5) * ((hypot(mlxdata->scale, mlxdata->scale)) / 2);
			((mapctr->map)[x][y]).y -= ((((float)mapctr->range - ((float)mapctr->max - (float)(mapctr->map[x][y].z))) / (float)mapctr->range) * 0.5) * ((hypot(mlxdata->scale, mlxdata->scale)) / 2);
		}
	}
}

int	fdf(char *file)
{
	int		fd;
	t_mlx	mlxdata;
	float	scale;
	int		*colors;

	if (!file)
		return (0);
	scale = 6;
	mlxdata.scale = scale;
	mlxdata.ptr = mlx_init();
	if (fdf_fileoperations(file, &mlxdata, scale))
	{
		fdf_findrange(&(mlxdata.mapctr));
		// fdf_relief(&mlxdata, &(mlxdata.mapctr));
		// mlxdata.win = mlx_new_window(mlxdata.ptr, \
		// 		mlxdata.mapctr.width * scale * PERSPECTIVE / sqrt(2) + mlxdata.mapctr.height * scale * PERSPECTIVE / sqrt(2), \
		// 		mlxdata.mapctr.height * scale / sqrt(2) + mlxdata.mapctr.width * scale / sqrt(2), "FdF");
		mlxdata.win = mlx_new_window(mlxdata.ptr, \
				WIN_WIDTH, \
				WIN_HEIGHT, "FdF");
		colors = fdf_colorgradient();
		mlxdata.colors = colors;
		fdf_colormap(&mlxdata, colors);
		if (colors && fdf_fill_img(&mlxdata, scale))
		{
			mlx_put_image_to_window(mlxdata.ptr, \
					mlxdata.win, mlxdata.img.ptr, 0, 0);
			mlx_loop(mlxdata.ptr);
		}
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
