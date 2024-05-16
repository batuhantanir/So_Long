#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"


void	print_map(t_map *map)
{
	int		i;
	int		j;
	void	*asd;

	i = 0;
	j = 0;
	map->mlx_win = mlx_new_window(map->mlx_ptr, 1920, 1080, "so_long");
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			// ft_printf("%s", map->map[i]);
			asd = mlx_new_image(map->mlx_ptr, 1920, 1080);
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, asd, 0, 0);
			// mlx_destroy_image(mlx_ptr, asd);
			j++;
		}
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	get_map(int fd, t_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			free(line);
			return ;
		}
		map->map = my_realloc(map->map, (map->height + 1) * sizeof(char *));
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0 || map->width < ft_strlen(line))
			map->width = ft_strlen(line);
		if (ft_strchr(line, 'P'))
		{
			map->playerY = map->height;
			map->playerX = ft_strchr(line, 'P') - line;
		}
	}
}
