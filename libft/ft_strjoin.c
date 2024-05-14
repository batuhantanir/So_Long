/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:34 by btanir            #+#    #+#             */
/*   Updated: 2023/12/10 20:00:10 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		s1len;
	int		s2len;

	i = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if ((!dest))
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	i = -1;
	while (s2[++i])
		dest[i + s1len] = s2[i];
	dest[s1len + i] = '\0';
	return (dest);
}
