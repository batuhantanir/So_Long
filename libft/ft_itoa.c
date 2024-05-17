/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:58:34 by btanir            #+#    #+#             */
/*   Updated: 2024/05/17 11:59:04 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (0 > num)
	{
		num = -num;
		i++;
	}
	while (0 < num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*dest;

	num = n;
	i = length(num);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	i--;
	if (num == 0)
		return (dest[0] = '0', dest);
	else if (0 > num)
	{
		dest[0] = '-';
		num = -num;
	}
	while (num)
	{
		dest[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (dest);
}
