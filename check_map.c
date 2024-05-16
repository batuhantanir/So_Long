#include "libft/libft.h"
#include "so_long.h"

void	check_bottom(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' && *line == '\n')
			handle_error("invalid border", -1);
		line++;
	}
}

void	check_top(char *line)
{
	while (*line != '\0' && *line != '\n')
	{
		if (*line != '1')
			handle_error("invalid border", -1);
		line++;
	}
}

void check_item(t_map *map)
{
	int i;
	int j;

	j = 0;

	while (j < map->height)
	{
		i = 0;
		while (i < map->width-2)
		{
			if (map->map[i][j] == 'P')
				map->player_count++;
			if (map->map[i][j] == 'C')
				map->collectible_count++;
			if (map->map[i][j] == 'E')
				map->exit_count++;
			if(map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'P' && map->map[i][j] != 'C' && map->map[i][j] != 'E')
				handle_error("Invalid item", -1);
			i++;
		}
		j++;
	}
}

void	check_middle(char **map, int height, int width)
{
	int	i;

	i = -1;
	while (++i < height - 1)
		if (map[i][0] != '1' || map[i][width - 2] != '1')
			handle_error("invalid border", -1);
		
}

void	check_map(t_map *map)
{
	void *area;

	area = map->map;
	if (map->height < 3 || map->width < 3)
		handle_error("Map is too small", -1);
	check_item(map);
	if(map->player_count != 1)
		handle_error("Player count is not 1", -1);
	if(map->collectible_count < 1)
		handle_error("Collectible count is less than 1", -1);
	if(map->exit_count != 1)
		handle_error("Exit count is not 1", -1);
	check_top(map->map[0]);
	check_middle(map->map, map->height, map->width);
	check_bottom(map->map[map->height - 1]);
	flood_fill(area, (t_point){map->width, map->height}, (t_point){map->playerX, map->playerY -1});
	check_flood_fill_map(map);
}
