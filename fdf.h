/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:33 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/08 18:17:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include "ft_colors.h"

# define ERR_OPEN "FdF: failed to open file.\n"
# define ERR_FILE "FdF: map error.\n"
# define ERR_ALLOC "FdF: failed to allocate memory.\n"

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1400

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}		t_point;

typedef struct s_mapctr
{
	t_point		**map;
	int			width;
	int			height;
	long		min;
	long		max;
	long		range;
}				t_mapctr;

typedef struct s_mlximg
{
	void	*ptr;
	char	*str;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlximg;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_mapctr	mapctr;
	t_mlximg	img;
	float		scale;
	int			*colors;
}				t_mlx;

/* Generic utility functions */
void		ft_colored_window(int w, int h);

/* FdF utility functions */
int			fdf_fileoperations(char *file, t_mlx *mlxdata, float scale);
t_point		**fdf_generate_map(int fd, t_mapctr *mapctr, float scale);
void		fdf_free_map(t_point **map);
void		fdf_print_map(t_mapctr mapctr);
void		fdf_findrange(t_mapctr *mapctr);
int			fdf_fill_img(t_mlx *mlxdata);
int			*fdf_colorgradient(void);
long		fdf_colorgradient_indice(t_mlx *mlxdata, int x, int y);
void		fdf_colormap(t_mlx *mlxdata, int *colors);
int			fdf_put_pixel(t_mlx *mlxdata, int color, char *pixel);
void		fdf_bresenham(t_mlx *data, t_point start, t_point end);
void		fdf_map_fill(t_mapctr *mapctr, int fd, float scale, float deg);

#endif
