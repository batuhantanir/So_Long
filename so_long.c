/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/10 14:59:33 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

void	get_map(int fd, struct s_map *map)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		map->map = realloc(map->map, sizeof(char *) * (map->height + 1));
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0)
			map->width = strlen(line);
	}
}

void	print_map(struct s_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s", map->map[i]);
		i++;
	}
}

void	free_map(struct s_map *map)
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

int	main(int argc, char **argv)
{
	int		i;
	t_map	map;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (!argv[1])
	{
		printf("Error\n");
		exit(1);
	}
	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		printf("Error\n");
		return (1);
	}
	map.map = NULL;
	map.width = 0;
	map.height = 0;
	get_map(i, &map);
	close(i);
	print_map(&map);
	free_map(&map);
	return (0);
}
