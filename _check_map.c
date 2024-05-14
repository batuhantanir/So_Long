#include "libft/libft.h"
#include "so_long.h"

void	check_map_if_should(t_map *map, int i, int j)
{
	if (map->height < 3 && map->width < 3 || map->map == NULL
		|| map->map[0] == NULL || map->map[0][0] == '\n' || map->map[map->height
		- 1][map->width - 1] == '\n' || map->map[0][0] != '1'
		|| map->map[0][map->width - 2] != '1' || map->map[map->height
		- 1][0] != '1' || map->map[map->height - 1][map->width - 2] != '1')
	{
		ft_printf("invalid map\n");
		exit(-1);
	}
}

void	check_border(t_map *map, int i, int j)
{
	if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1'
		|| map->map[i][0] != '1' || map->map[i][map->width - 2] != '1')
	{
		ft_printf("invalid border\n");
		exit(-1);
	}
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	printf("map->height: %d\n", map->height);
	printf("map->width: %d\n", map->width);
	while (map->map[i] != NULL && i < map->height)
	{
		j = 0;
		while (map->map[i][j] != '\0' && j < map->width - 2)
		{
			check_map_if_should(map, i, j);
			check_border(map, i, j);
			j++;
		}
		i++;
	}
}

void check_map(t_map *map)
{

}