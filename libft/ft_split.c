/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:49:28 by aaksoy            #+#    #+#             */
/*   Updated: 2023/12/11 18:27:16 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
		while (s[j] && s[j] == c)
			j++;
	}
	return (i);
}

static void	*free_str(char **ptr, int j)
{
	while (j > 0)
		free(ptr[--j]);
	free(ptr);
	return (NULL);
}

static int	ft_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		j;
	char	*s1;

	s1 = (char *)s;
	ptr = (char **)malloc(sizeof(char *) * (count_word(s1, c) + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (*s1)
	{
		while (*s1 && *s1 == c)
			s1++;
		if (*s1 && *s1 != c)
		{
			ptr[j] = ft_substr(s1, 0, ft_len(s1, c));
			if (!ptr[j])
				return (free_str(ptr, j));
			j++;
		}
		while (*s1 && *s1 != c)
			s1++;
	}
	ptr[j] = NULL;
	return (ptr);
}
