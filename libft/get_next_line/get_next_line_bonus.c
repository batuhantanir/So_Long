/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:46:13 by btanir            #+#    #+#             */
/*   Updated: 2024/02/25 14:54:57 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_readline(int fd, char *temp)
{
	char	*buffer;
	int		error;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	error = 1;
	while (error != 0 && (!ft_strchr(temp)))
	{
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[error] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*ft_before_next_line(char *stash)
{
	int		i;
	char	*to_return;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	to_return = malloc((sizeof(char) * (i + 2)));
	if (!to_return)
		return (NULL);
	ft_strcpy(to_return, stash, i + 1);
	return (to_return);
}

char	*ft_new_line(char *stash)
{
	int		i;
	char	*to_return ;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	to_return = (char *)malloc((sizeof(char) * (ft_strlen(stash) - i + 1)));
	if (!to_return)
		return (free(stash), NULL);
	i++;
	ft_strcpy(to_return, stash + i, ft_strlen(stash + i));
	free(stash);
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*temp[128];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = ft_readline(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	str = ft_before_next_line(temp[fd]);
	temp[fd] = ft_new_line(temp[fd]);
	return (str);
}
