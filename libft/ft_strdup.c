/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:55:10 by btanir            #+#    #+#             */
/*   Updated: 2023/12/02 19:59:30 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new;

	len = ft_strlen(str);
	new = (char *)malloc((len * sizeof(char)) + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, str, len);
	new[len] = '\0';
	return (new);
}
