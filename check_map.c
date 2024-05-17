#include "libft/libft.h"
#include "so_long.h"

void	check_bottom(char *line, t_map *map)
{
	while (*line != '\0')
	{
		if (*line != WALL || *line == '\n')
			handle_error("invalid borderb", -1, map);
		line++;
	}
}

void	check_top(char *line, t_map *map)
{
	while (*line != '\0')
	{
		if (*line != WALL && *line != '\n')
			handle_error("invalid bordert", -1, map);
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
			if (map->map[i][j] == PLAYER)
				map->player_count++;
			if (map->map[i][j] == COLLECTIBLE)
				map->collectible_count++;
			if (map->map[i][j] == EXIT)
				map->exit_count++;
			if (map->map[i][j] != WALL && map->map[i][j] != SPACE
				&& map->map[i][j] != PLAYER && map->map[i][j] != COLLECTIBLE
				&& map->map[i][j] != EXIT)
				handle_error("Invalid item", -1, map);
			i++;
		}
		j++;
	}
}

void	check_map(t_map *map)
{
	if (map->height < 3 || map->width < 3)
		handle_error("Map is too small", -1, map);
	check_item(map);
	if (map->player_count != 1 || map->player->x == 0 || map->player->y == 0)
		handle_error("Player count is not 1", -1, map);
	if (map->collectible_count < 1)
		handle_error("Collectible count is less than 1", -1, map);
	if (map->exit_count != 1)
		handle_error("Exit count is not 1", -1, map);
	check_top(map->map_copy[0], map);
	check_middle(map, map->height, map->width);
	check_bottom(map->map_copy[map->height - 1], map);
	flood_fill(map->map_copy, (t_point){map->width, map->height},
		(t_point){map->player->x, map->player->y - 1});
	check_flood_fill_map(map);
}
