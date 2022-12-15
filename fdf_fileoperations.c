/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fileoperations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:42:04 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/15 16:19:23 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_set_mapsize__width(char *line)
{
	int		line_width;
	size_t	i;

	line_width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			line_width++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
			if (line[i] == '0' && line [i + 1] == 'x' && i++)
			{
				while (line[++i])
					if (!(('0' <= line[i] && line[i] <= '9')
							|| ('a' <= line[i] && line[i] <= 'f')
							|| ('A' <= line[i] && line[i] <= 'F')))
						break ;
			}
		}
		else
			i++;
	}
	return (line_width);
}

static int	fdf_set_mapsize(int fd, t_mapctr *mapctr)
{
	char	*line;
	int		line_width;

	mapctr->width = 0;
	mapctr->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_width = fdf_set_mapsize__width(line);
		if (line_width > mapctr->width)
			mapctr->width = line_width;
		(mapctr->height)++;
		free(line);
	}
	close(fd);
	if (mapctr->width <= 0 || mapctr->height <= 0)
		return (0);
	return (1);
}

static int	fileoperations2(char *file, t_mlx *data)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_OPEN), 0);
	fdf_generate_map(fd, &(data->mapctr));
	close(fd);
	if (!data->mapctr.map)
		return (ft_printf(ERR_ALLOC), 0);
	return (1);
}

int	fdf_fileoperations(char *file, t_mlx *data)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_OPEN), 0);
	if (!fdf_set_mapsize(fd, &(data->mapctr)))
		return (ft_printf(ERR_FILE), 0);
	data->img.ptr = mlx_new_image(data->ptr, \
			WIN_WIDTH, WIN_HEIGHT);
	if (!(data->img.ptr))
		return(ft_printf(ERR_MLX), 0);
	data->img.str = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bpp), &(data->img.size_line), \
			&(data->img.endian));
	if (!(data->img.str))
		return(ft_printf(ERR_MLX), 0);
	return(fileoperations2(file, data));
}
