/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/11 18:06:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_initialisation(t_mlx *data)
{
	data->ptr = NULL;
	data->win = NULL;
	data->mapctr.map = NULL;
	data->img.ptr = NULL;
	data->img.str = NULL;
	data->colors = NULL;
}

int	fdf(char *file)
{
	t_mlx	data;

	if (!file)
		return (0);
	fdf_initialisation(&data);
	data.ptr = mlx_init();
	if (fdf_fileoperations(file, &data))
	{
		data.win = mlx_new_window(data.ptr, \
				WIN_WIDTH, \
				WIN_HEIGHT, "FdF");
		data.gradient = 1;
		data.colors = fdf_colorgradient(&data);
		if (!(data.colors))
			return (ft_printf(ERR_ALLOC), 0);
		fdf_colormap(&data, data.colors);
		fdf_default(&data);
		mlx_key_hook(data.win, fdf_keypressed, &data);
		mlx_mouse_hook(data.win, fdf_mouseclick, &data);
		mlx_loop(data.ptr);
	}
	else
		return (0);
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
