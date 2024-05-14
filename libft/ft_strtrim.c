/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:44:53 by btanir            #+#    #+#             */
/*   Updated: 2023/12/10 19:09:47 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char const *s, char const c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (set_check(set, *s1))
			s1++;
		else
			break ;
	}
	a = ft_strlen(s1);
	while (a != 0)
	{
		if (set_check(set, s1[a - 1]))
			a--;
		else
			break ;
	}
	str = (char *)malloc((a * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, a + 1);
	return (str);
}
