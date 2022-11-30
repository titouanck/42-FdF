/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:24:16 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 02:30:53 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	*new_tcolor(int color)
{
	t_color	*elem;

	elem = malloc(sizeof(t_color));
	if (!elem)
		return (NULL);
	elem->value = color;
	elem->red = red_color(color);
	elem->green = green_color(color);
	elem->blue = blue_color(color);
	return (elem);
}

int	change_tcolor(t_color *elem, int color)
{
	if (!elem)
		return (0);
	elem->value = color;
	elem->red = red_color(color);
	elem->green = green_color(color);
	elem->blue = blue_color(color);
	return (1);
}
