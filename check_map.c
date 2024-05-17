#include "libft/libft.h"
#include "so_long.h"

void	check_bottom(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' || *line == '\n')
			handle_error("invalid borderb", -1);
		line++;
	}
}

void	check_top(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' && *line != '\n')
			handle_error("invalid bordert", -1);
		line++;
	}
}

void	check_middle(char **map, int height, int width)
{
	int	i;

	i = -1;
	while (++i < height - 1)
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			handle_error("invalid borderm", -1);
		
}
void check_item(t_map *map)
{
	int i;
	int j;

	j = 0;

	while (j < map->height)
	{ 
		i = 0;
		while (i < map->width-1)
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

void	check_map(t_map *map)
{
	if (map->height < 3 || map->width < 3)
		handle_error("Map is too small", -1);
	check_item(map);
	if(map->player_count != 1 || map->playerX == 0 || map->playerY == 0)
		handle_error("Player count is not 1", -1);
	if(map->collectible_count < 1)
		handle_error("Collectible count is less than 1", -1);
	if(map->exit_count != 1)
		handle_error("Exit count is not 1", -1);
	check_top(map->map_copy[0]);
	check_middle(map->map_copy, map->height, map->width);
	check_bottom(map->map_copy[map->height - 1]);
	print_map(map->map, map->height);
	printf("width: %d, height: %d,  player.x: %d, player.y: %d", map->width, map->height, map->playerX, map->playerY);
	flood_fill(map->map_copy, (t_point){map->width, map->height}, (t_point){map->playerX, map->playerY -1});
	check_flood_fill_map(map);
	print_map(map->map_copy, map->height);
}
