/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:01:33 by btanir            #+#    #+#             */
/*   Updated: 2023/12/28 15:47:32 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i += ft_putstr("(null)");
	else
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
			i++;
		}
	}
	return (i);
}

int	ft_putnbr_base(long long nbr, int base, int is_upper)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		i++;
	}
	if (nbr >= base)
	{
		i += ft_putnbr_base(nbr / base, base, is_upper);
		i += ft_putnbr_base(nbr % base, base, is_upper);
	}
	else
	{
		if (is_upper)
			i += ft_putchar("0123456789ABCDEF"[nbr % base]);
		else
			i += ft_putchar("0123456789abcdef"[nbr % base]);
	}
	return (i);
}

int	ft_ptr(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_ptr(nbr / 16);
		i += ft_ptr(nbr % 16);
	}
	else
	{
		i += ft_putchar("0123456789abcdef"[nbr % 16]);
	}
	return (i);
}
