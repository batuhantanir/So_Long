/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:47:15 by btanir            #+#    #+#             */
/*   Updated: 2024/05/16 19:31:51 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_readline_gnl(int fd, char *temp)
{
	char	*buffer;
	int		error;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	error = 1;
	while (error != 0 && (!ft_strchr_gnl(temp)))
	{
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[error] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*ft_before_next_line_gnl(char *stash)
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
	ft_strcpy_gnl(to_return, stash, i + 1);
	return (to_return);
}

char	*ft_new_line_gnl(char *stash)
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
	to_return = (char *)malloc((sizeof(char) * (ft_strlen_gnl(stash) - i + 1)));
	if (!to_return)
		return (free(stash), NULL);
	i++;
	ft_strcpy_gnl(to_return, stash + i, ft_strlen_gnl(stash + i));
	free(stash);
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_readline_gnl(fd, temp);
	if (!temp)
		return (NULL);
	str = ft_before_next_line_gnl(temp);
	temp = ft_new_line_gnl(temp);
	return (str);
}
