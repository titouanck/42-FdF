/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/06 20:13:58 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(char *file)
{
	int		fd;
	t_mlx	mlxdata;
	float	scale;
	int		*colors;

	if (!file)
		return (0);
	scale = 100;
	mlxdata.ptr = mlx_init();
	if (fdf_fileoperations(file, &mlxdata, scale))
	{
		fdf_findrange(&(mlxdata.mapctr));
		mlxdata.win = mlx_new_window(mlxdata.ptr, \
				(float)mlxdata.mapctr.width * scale, \
				(float)mlxdata.mapctr.height * scale, "FdF");
		colors = fdf_colorgradient();
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
