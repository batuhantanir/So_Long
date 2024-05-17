/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:45:40 by btanir            #+#    #+#             */
/*   Updated: 2024/05/17 10:25:29 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_converter(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == COLLECTIBLE)
		i += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_base(va_arg(arg, int), 10, 0);
	else if (c == 'u')
		i += ft_putnbr_base(va_arg(arg, unsigned int), 10, 0);
	else if (c == 'x')
		i += ft_putnbr_base(va_arg(arg, unsigned int), 16, 0);
	else if (c == 'X')
		i += ft_putnbr_base(va_arg(arg, unsigned int), 16, 1);
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_ptr(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		i += ft_putchar('%');
	else
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_converter(*(str + 1), arg);
			str++;
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (i);
}
