/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:09:20 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 19:05:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include "colors.h"

# ifndef SCALE
#  define SCALE 60
# endif
# define ERR_OPEN "FdF: failed to open file.\n"

typedef struct s_map
{
	void	*img;
	int		width;
	int		height;
	char	*buf;
	int		bpp;
	int		size_line;
	int		endian;
	int		**map;
	int		min;
	int		max;
}			t_map;

/* Generic utility functions */
void	ft_colored_window(int w, int h);

/* fdf utility functions */
void	fdf_mapsize(int fd, int *width, int *height);
int		fdf_printfile(char *file);
int		fdf_map3d(char *file);
int		**fdf_mapgenerate(int fd, int width, int height);
void	fdf_mapfree(int **map);
void	fdf_mapprint(t_map *map);
void	fdf_maptoscreen(t_map *map, void *mlx_ptr);

/* fdf lstmap functions */
t_map	*fdf_lstmap_new(void *mlx_ptr, int fd);
void	fdf_lstmap_free(void *mlx_ptr, t_map *map);

#endif