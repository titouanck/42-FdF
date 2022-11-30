/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:24:16 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/30 18:09:16 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	*lstcolor_new(int color)
{
	t_color	*elem;

	elem = malloc(sizeof(t_color));
	if (!elem)
		return (NULL);
	elem->val = color;
	elem->r = red_color(color);
	elem->g = green_color(color);
	elem->b = blue_color(color);
	return (elem);
}

int	lstcolor_change(t_color *elem, int color)
{
	if (!elem)
		return (0);
	elem->val = color;
	elem->r = red_color(color);
	elem->g = green_color(color);
	elem->b = blue_color(color);
	return (1);
}
