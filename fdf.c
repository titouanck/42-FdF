/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:55:20 by tchevrie          #+#    #+#             */
/*   Updated: 2022/12/01 00:57:03 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc == 1)
	{		
		ft_printf("FdF: missing file operand\n");
		ft_printf("Usage: ./FdF [FILE]\n");
		// ft_printf("Usage: ./FdF [FILE] [FILE] ...\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!fdf_printfile(argv[i]) || !fdf_map3d(argv[i]))
			ft_printf("Error occurred for argument \"%s\"\n", argv[i]);
		i++;
		if (i < argc)
			ft_printf("\n");
	}
	return (0);
}
