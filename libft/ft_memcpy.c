/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:18:33 by btanir            #+#    #+#             */
/*   Updated: 2023/12/14 19:13:14 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*s;

	if (!dst && !src)
		return (0);
	c = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		c[i] = s[i];
		i++;
	}
	return (dst);
}
