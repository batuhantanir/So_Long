/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:39:04 by btanir            #+#    #+#             */
/*   Updated: 2024/05/18 15:17:58 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	check_top_bottom(char *line, t_map *map)
{
	while (*line == '1')
	{
		if (*line != WALL)
			handle_error("invalid border", -1, map);
		line++;
	}
}

void	check_middle(t_map *map, int height, int width)
{
	int	i;

	i = -1;
	while (++i < height - 1)
		if (map->map_copy[i][0] != WALL || map->map_copy[i][width - 1] != WALL)
			handle_error("invalid borderm", -1, map);
}

void	check_item(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width - 1)
		{
			if (map->map[j][i] == PLAYER)
				map->player_count++;
			if (map->map[j][i] == COLLECTIBLE)
				map->collectible_count++;
			if (map->map[j][i] == EXIT)
				map->exit_count++;
			if (ft_strchr(ELEMENTS, map->map[j][i]) == NULL)
				handle_error("Invalid item2", -1, map);
			i++;
		}
		j++;
	}
}

void	check_map(t_map *map)
{
	t_point	*begin;

	if (map->height < 3 || map->width < 3)
		handle_error("Map is too small", -1, map);
	check_item(map);
	if (map->player_count != 1 || map->player.x == 0 || map->player.y == 0)
		handle_error("Player count is not 1", -1, map);
	if (map->collectible_count < 1)
		handle_error("Collectible count is less than 1", -1, map);
	if (map->exit_count != 1)
		handle_error("Exit count is not 1", -1, map);
	check_top_bottom(map->map_copy[0], map);
	check_middle(map, map->height, map->width);
	check_top_bottom(map->map_copy[map->height - 1], map);
	begin = (t_point *)malloc(sizeof(t_point));
	begin->x = map->player.x;
	begin->y = map->player.y;
	flood_fill(map, begin);
	check_flood_fill_map(map);
	free(begin);
}
