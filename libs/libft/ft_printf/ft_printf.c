/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:03:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/28 14:43:47 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	conversion(const char *c, size_t *i, va_list *ap)
{
	*i = *i + 1;
	if (*(c + 1) == 'c')
		return (ft_putchar((char) va_arg(*ap, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putadress(va_arg(*ap, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr(va_arg(*ap, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_puthexa_lower(va_arg(*ap, int)));
	else if (*(c + 1) == 'X')
		return (ft_puthexa_upper(va_arg(*ap, int)));
	else if (*(c + 1) == '%')
		return (ft_putchar('%'));
	else if (*(c + 1) && *(c + 2))
		return (ft_putchar(*(c)) + ft_putchar(*(c + 1)));
	else
	{
		*i -= 1;
		return (-1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		tmp;
	va_list	ap;
	size_t	i;

	if (!str)
		return (-1);
	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = conversion(str + i, &i, &ap);
		else
			tmp = ft_putchar(str[i]);
		if (tmp >= 0)
			len += tmp;
		else
			len = tmp;
		i++;
	}
	va_end(ap);
	return (len);
}
