#include "libft/libft.h"
#include "so_long.h"

void	handle_error(char *message, int err_no, t_map *map)
{
	ft_printf("%s\n", message);
	free_map(map, map->height);
	exit(err_no);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.x >= size.x)
		return ;
	if (area[begin.y][begin.x] == WALL || area[begin.y][begin.x] == 'F')
		return ;
	area[begin.y][begin.x] = 'F';
	begin.x++;
	if (begin.x < size.x && area[begin.y][begin.x] != WALL)
		flood_fill(area, size, begin);
	begin.x -= 2;
	if (begin.x > 0 && area[begin.y][begin.x] != WALL)
		flood_fill(area, size, begin);
	begin.x++;
	begin.y++;
	if (begin.y < size.y - 1 && area[begin.y][begin.x] != WALL)
		flood_fill(area, size, begin);
	begin.y -= 2;
	if (begin.y > 0 && area[begin.y][begin.x] != WALL)
		flood_fill(area, size, begin);
}

void	check_flood_fill_map(t_map *map)
{
	int i;
	int j;
	i = 0;

	while (i < map->height)
	{
		j = 0;
		while (map->map_copy[i][j] != '\0')
		{
			if (map->map_copy[i][j] == PLAYER)
				handle_error("Player is not surrounded by walls", -1, map);
			if (map->map_copy[i][j] == EXIT)
				handle_error("Exit is not surrounded by walls", -1, map);
			if (map->map_copy[i][j] == COLLECTIBLE)
				handle_error("Collectible is not surrounded by walls", -1, map);
			j++;
		}
		i++;
	}
}