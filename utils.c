#include "libft/libft.h"
#include "so_long.h"

void	handle_error(char *message, int err_no, t_map *map)
{
	ft_printf("%s\n", message);
	free_map(map, map->height);
	exit(err_no);
}

void	flood_fill(t_map *map, t_point *begin)
{
	if (begin->x <= 0 || begin->y <= 0 || begin->x >= map->width 
		|| begin->y >= map->height )
		return ;
	map->map_copy[begin->y][begin->x] = 'F';
	begin->x += 1;
	if (begin->x <= map->height && ft_strchr(ELEMENTS_KEK,
			map->map_copy[begin->y][begin->x]))
		flood_fill(map, begin);
	begin->x -= 2;
	if (begin->x >= 0 && ft_strchr(ELEMENTS_KEK,
			map->map_copy[begin->y][begin->x]))
		flood_fill(map, begin);
	begin->x += 1;
	begin->y += 1;
	if (begin->y <= map->width && ft_strchr(ELEMENTS_KEK,
			map->map_copy[begin->y][begin->x]))
		flood_fill(map, begin);
	begin->y -= 2;
	if (begin->y >= 0 && ft_strchr(ELEMENTS_KEK,
			map->map_copy[begin->y][begin->x]))
		flood_fill(map, begin);
	begin->y += 1;
}

void	check_flood_fill_map(t_map *map)
{
	int i;
	int j;
	i = 0;

	while (i < map->height)
	{
		printf("map->map_copy[%d] = %s\n", i, map->map_copy[i]);
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