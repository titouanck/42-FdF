/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:33 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/05 18:39:41 by tchevrie         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_mapctr
{
	t_point	**tpoint;
	int		**map;
	int		width;
	int		height;
	int		min;
	int		max;
	long	range;
}			t_mapctr;

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
}				t_mlx;

/* Generic utility functions */
void		ft_colored_window(int w, int h);

/* FdF utility functions */
int			fdf_fileoperations(char *file, t_mlx *mlxdata, float scale);
int			**fdf_generate_map(int fd, t_mapctr *mapctr);
void		fdf_free_map(int **map);
void		fdf_print_map(t_mapctr mapctr);
void		fdf_findrange(t_mapctr *mapctr);
int			fdf_fill_img(t_mlx *mlxdata, float scale);
int			*fdf_colorgradient(void);

/* FdF lst functions */

#endif
