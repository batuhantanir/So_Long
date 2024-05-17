/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/17 10:29:55 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

void	*my_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
	{
		printf("Yeniden boyutlandırma başarısız oldu!\n");
		free(ptr);
		exit(EXIT_FAILURE);
	}
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

void	ft_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->map_copy = NULL;
	map->mlx_ptr = NULL;
	map->mlx_win = NULL;
	map->player->x = 0;
	map->player->y = 0;
	map->exit->x = 0;
	map->exit->y = 0;
	map->player_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2 || strstr(argv[1], ".ber") == NULL)
	{
		printf("Invalid argument\n");
		exit(EXIT_FAILURE);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("Memory allocation failed", -1, map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error("File could not be opened", -1, map);
	ft_init(map);
	get_map(fd, map);
	close(fd);
	check_map(map);
	print_map(map);
	mlx_loop(map->mlx_ptr);
	free_map(map, map->height);
	system("leaks so_long");
	return (0);
}
