/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/06/01 13:00:11 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static void	check_map_name(char *map_name);
static void	ft_init(t_map *map);

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (ft_printf("Error: Must have 2 arguments!\n"), 0);
	check_map_name(argv[1]);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("Memory allocation failed", -1, map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: File open error\n");
		exit(-1);
	}
	ft_init(map);
	get_map(fd, map);
	close(fd);
	check_map(map);
	print_map(map);
	free_map(map, map->height);
	return (0);
}

static void	check_map_name(char *map_name)
{
	if (ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Invalid map name\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->map_copy = NULL;
	map->mlx_ptr = NULL;
	map->mlx_win = NULL;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->player_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
	map->moves = 0;
	map->imgs.img_0 = NULL;
	map->imgs.img_1 = NULL;
	map->imgs.img_empty = NULL;
	map->imgs.img_player = NULL;
	map->imgs.img_collectible = NULL;
}
