/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:06:25 by btanir            #+#    #+#             */
/*   Updated: 2023/12/14 19:25:41 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		s;
	size_t	d;
	size_t	di;
	int		si;

	si = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (si);
	d = ft_strlen(dst);
	di = d;
	if (dstsize <= di)
		return (dstsize + si);
	s = 0;
	while (src[s] && d < dstsize - 1)
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (di + si);
}
