#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

void	print_map(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
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
int	ft_custom_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	add_line(t_map *map, char *line)
{
	map->map = (char **)my_realloc(map->map, sizeof(char *) * (map->height
				+ 1));
	map->map[map->height] = (char *)malloc(sizeof(char) * (map->width + 1));
	map->map_copy = (char **)my_realloc(map->map_copy, sizeof(char *)
			* (map->height + 1));
	map->map_copy[map->height] = (char *)malloc(sizeof(char) * (map->width
				+ 1));
	if (!map->map[map->height] || !map->map || !map->map_copy
		|| !map->map_copy[map->height])
		handle_error("Memory allocation failed", -1);
	ft_memcpy(map->map[map->height], line, map->width);
	ft_memcpy(map->map_copy[map->height], line, map->width);
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
		handle_error("Invalid map", -1);
	}
}

void	playe_position(t_map *map, char *line)
{
	if (ft_strchr(line, 'P'))
	{
		map->playerY = map->height;
		map->playerX = ft_strchr(line, 'P') - line;
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
		tmp = strdup(line);
		check_width(line, map);
		add_line(map, line);
		playe_position(map, tmp);
		free(line);
	}
	if (tmp[map->width] == '\n')
	{
		handle_error("Invalid map", -1);
		free(tmp);
	}
}
