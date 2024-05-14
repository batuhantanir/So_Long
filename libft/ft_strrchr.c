/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:43:31 by btanir            #+#    #+#             */
/*   Updated: 2023/12/10 20:00:22 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;
	char	*d;

	d = (char *)s;
	slen = ft_strlen(d);
	while (slen >= 0)
	{
		if (d[slen] == (char)c)
			return (d + slen);
		if (slen == 0)
			break ;
		slen--;
	}
	return (0);
}
