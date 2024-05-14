/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:20:19 by btanir            #+#    #+#             */
/*   Updated: 2023/12/10 20:00:06 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	int				slen;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = (unsigned char)(c);
	slen = ft_strlen(s);
	while (i <= slen)
	{
		b = (unsigned char)s[i];
		if (b == a)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
