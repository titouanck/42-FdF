/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:40:55 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 18:09:28 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdlib.h>

# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define ORANGE 0xFF6600
# define PURPLE 0x6600FF

typedef struct s_color
{
	int				val;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

// RGB
int				rgb(unsigned char red, unsigned char green, unsigned char blue);
unsigned char	red_color(int color);
unsigned char	green_color(int color);
unsigned char	blue_color(int color);

// ELEMS
t_color			*lstcolor_new(int color);
int				lstcolor_change(t_color *elem, int color);

#endif
