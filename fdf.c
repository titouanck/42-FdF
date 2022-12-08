/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 12:23:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_relief(t_mlx *mlxdata, t_mapctr *mapctr)
{
	long	x;
	long	y;
	float	angle;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			((mapctr->map)[x][y]).x += 0;
			((mapctr->map)[x][y]).y += 0;
			// printf("((mapctr->range = %ld) - (mapctr->max - mapctr->map[x][y].z = %ld)) / (mapctr->range = %ld)\n\n", mapctr->range, mapctr->max - (long)(mapctr->map[x][y].z), mapctr->range);
			// printf("Calcul result: %ld(%ld)\n", (mapctr->range - (mapctr->max - mapctr->map[x][y].z)) / mapctr->range);
			printf("Result: %f\n", ((mapctr->range - (mapctr->max - (long)(mapctr->map[x][y].z))) / mapctr->range) * 0.75);
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
	scale = 35;
	mlxdata.scale = scale;
	mlxdata.ptr = mlx_init();
	if (fdf_fileoperations(file, &mlxdata, scale))
	{
		fdf_findrange(&(mlxdata.mapctr));
		fdf_relief(&mlxdata, &(mlxdata.mapctr));
		// mlxdata.win = mlx_new_window(mlxdata.ptr, \
		// 		(float)mlxdata.mapctr.width * scale, \
		// 		(float)mlxdata.mapctr.height * scale, "FdF");
		// mlxdata.win = mlx_new_window(mlxdata.ptr, \
		// 		hypotf(mlxdata.mapctr.width * scale, mlxdata.mapctr.height * scale), \
		// 		hypotf(mlxdata.mapctr.height * scale, mlxdata.mapctr.width * scale), "FdF");
		mlxdata.win = mlx_new_window(mlxdata.ptr, \
				mlxdata.mapctr.width * scale * PERSPECTIVE / sqrt(2) + mlxdata.mapctr.height * scale * PERSPECTIVE / sqrt(2), \
				mlxdata.mapctr.height * scale / sqrt(2) + mlxdata.mapctr.width * scale / sqrt(2), "FdF");
		// mlxdata.win = mlx_new_window(mlxdata.ptr, \
		// 		WIN_WIDTH * 0.8, \
		// 		WIN_HEIGHT * 0.8, "FdF");
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
