/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_printfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:16:47 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/02 01:07:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_printfile(char *file)
{
	int		fd;
	char	*line;

	if (!file)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_OPEN), 0);
	ft_printf("(%s)\n", file);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break ;
	// 	ft_printf(line);
	// 	free(line);
	// }
	// ft_printf("\n\n");
	return (close(fd), 1);
}
