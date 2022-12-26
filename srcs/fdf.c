/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:35:59 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/26 16:23:13 by tchevrie         ###   ########.fr       */
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
	data->gradient = 1;
	data->mapctr.min = 2147483647;
	data->mapctr.max = -2147483648;
}

static int	fdf_quit(void *param)
{
	exit(fdf_free_all((t_mlx *)param));
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
				WIN_WIDTH, WIN_HEIGHT, "FdF");
		data.colors = fdf_colorgradient(&data);
		if (!(data.colors))
			return (ft_printf(ERR_ALLOC), fdf_free_all(&data), 0);
		fdf_colormap(&data, data.colors);
		fdf_default(&data);
		mlx_hook(data.win, 02, (1L << 0), fdf_keypressed, &data);
		mlx_hook(data.win, 17, 0, fdf_quit, &data);
		mlx_mouse_hook(data.win, fdf_mouseclick, &data);
		mlx_loop(data.ptr);
		return (1);
	}
	fdf_free_all(&data);
	return (0);
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
