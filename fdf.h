/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:09:20 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 22:52:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include "colors.h"

# define ERR_OPEN "FdF: failed to open file.\n"

typedef struct s_map
{
	int		width;
	int		height;
	int		**map;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
}			t_map;

/* Utils */
void	ft_colored_window(int w, int h);

/* fdf functions */
void	fdf_mapsize(int fd, int *width, int *height);
int		fdf_printfile(char *file);
int		fdf_map3d(char *file);
t_map	*fdf_lstmap_new(void *mlx_ptr, int fd);
int		**fdf_mapgenerate(int fd, int width, int height);
void	fdf_mapfree(int **map);
void	fdf_mapprint(t_map *map);

#endif