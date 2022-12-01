/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:14:29 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 19:23:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	width_on_line(char *line)
{
	int		pixels;
	size_t	i;

	pixels = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			pixels++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (pixels);
}

void	fdf_mapsize(int fd, int *width, int *height)
{
	char	*line;
	int		pixels;

	*width = 0;
	*height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		pixels = width_on_line(line);
		if (pixels > *width)
			*width = pixels;
		(*height)++;
		free(line);
	}
}
