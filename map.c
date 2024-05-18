/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:25:50 by btanir            #+#    #+#             */
/*   Updated: 2024/05/18 21:23:26 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

void	free_map(t_map *map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map->map[i]);
		free(map->map_copy[i]);
		i++;
	}
	free(map->map);
	free(map->map_copy);
}

void	add_line(t_map *map, char *line)
{
	map->map = (char **)my_realloc(map->map, sizeof(char *) * (map->height
				+ 1));
	map->map[map->height] = ft_strdup(line);
	map->map_copy = (char **)my_realloc(map->map_copy, sizeof(char *)
			* (map->height + 1));
	map->map_copy[map->height] = ft_strdup(line);
	if (!map->map[map->height] || !map->map || !map->map_copy
		|| !map->map_copy[map->height])
		handle_error("Memory allocation failed", -1, map);
	map->height++;
}

void	check_width(char *line, t_map *map)
{
	if (map->height == 0)
	{
		map->width = ft_custom_strlen(line);
	}
	else if (map->width != ft_custom_strlen(line))
	{
		free(line);
		handle_error("Invalid map", -1, map);
	}
}

void	player_exit_position(t_map *map, char *line)
{
	if (ft_strchr(line, PLAYER) && map->player.y == 0 && map->player.x == 0)
	{
		map->player.y = map->height - 1;
		map->player.x = ft_strchr(line, PLAYER) - line;
	}
	if (ft_strchr(line, EXIT) && map->exit.y == 0 && map->exit.x == 0)
	{
		map->exit.y = map->height - 1;
		map->exit.x = ft_strchr(line, EXIT) - line;
	}
}

void	get_map(int fd, t_map *map)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			free(line);
			break ;
		}
		tmp = line;
		check_width(line, map);
		add_line(map, line);
		if (map->player.y == 0 || map->exit.y == 0 || map->player.x == 0
			|| map->exit.x == 0)
			player_exit_position(map, tmp);
		free(line);
	}
	if (tmp[map->width] == '\n')
	{
		handle_error("Invalid map", -1, map);
		free(tmp);
	}
}
