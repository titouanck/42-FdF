/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 23:53:37 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
		mlxdata.scale = 40;
		mlxdata.deg = 45;
		mlxdata.ix = 1;
		mlxdata.iy = 0.5;
		fdf_map_to_screen(&mlxdata, mlxdata.deg, mlxdata.ix, mlxdata.iy);
		mlx_key_hook(mlxdata.win, (* fdf_keypressed), &mlxdata);
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
