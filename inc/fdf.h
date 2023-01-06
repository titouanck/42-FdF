/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:33 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/06 06:43:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include "ft_colors.h"
# include "keyboardvalues.h"

# define ERR_OPEN "FdF: failed to open file.\n"
# define ERR_FILE "FdF: map error.\n"
# define ERR_ALLOC "FdF: failed to allocate memory.\n"
# define ERR_LIBMLX "FdF: mlx failed to allocate memory.\n"

# ifndef RAD
#  define RAD 57.2958
# endif

# ifdef MACOS
#  define WIN_WIDTH 1470
#  define WIN_HEIGHT 889
# endif

# ifndef MACOS
#  define WIN_WIDTH 1560
#  define WIN_HEIGHT 1325
# endif

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
	long		translatex;
	long		translatey;
	float		xorigin;
	float		yorigin;
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
	int			*colors;
	int			nbrcolors;
	int			gradient;
	float		scale;
	float		relief;
	float		deg;
	float		deg_sin;
	float		deg_cos;
	float		iy;
	float		iy_sin;
	float		iy_cos;
}				t_mlx;

typedef struct s_bresenham
{
	float	ratio;
	t_point	current;
	float	diff;
	float	i;
	t_color	scl;
	t_color	ecl;
}			t_bresenham;

int			fdf_fileoperations(char *file, t_mlx *data);
t_point		**fdf_generate_map(int fd, t_mapctr *mapctr);
void		fdf_free_map(t_point **map);
void		fdf_print_map(t_mapctr mapctr);
void		fdf_findrange(t_mapctr *mapctr);
void		fdf_fill_img(t_mlx *data);
int			*fdf_colorgradient(t_mlx *data);
long		fdf_colorgradient_indice(t_mlx *data, int x, int y);
void		fdf_colormap(t_mlx *data, int *colors);
void		fdf_empty_colormap(t_mlx *data, int *colors);
int			fdf_put_pixel(t_mlx *data, int color, char *pixel);
void		fdf_bresenham(t_mlx *data, t_point start, t_point end);
int			fdf_parallel(t_mlx *dt);
void		fdf_map_fill(t_mlx *data);
int			fdf_map_to_screen(t_mlx *data);
float		fdf_get_scale(t_mlx *data);
int			fdf_keypressed(int key, void *param);
int			fdf_mouseclick(int key, int x, int y, void *param);
int			fdf_flat(t_mlx *data);
int			fdf_default(void *param);
int			fdf_changecolor(t_mlx *data);
int			fdf_free_all(t_mlx *data);
void		fdf_clear_img(t_mlx *data);
int			fdf_atoi_color(const char *str, t_mapctr *mapctr, int x, int y);
void		fdf_bresenham_if(t_mlx *d, t_point s, t_point e, float ratio);
void		fdf_bresenham_else(t_mlx *d, t_point s, t_point e, float ratio);
void		fdf_call_put_pixel(t_mlx *data, t_point current);
#endif
