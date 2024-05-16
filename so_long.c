/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/16 20:13:54 by btanir           ###   ########.fr       */
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

void ft_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->map_copy = NULL;
	map->mlx_ptr = NULL;
	map->mlx_win = NULL;
	map->playerX = 0;
	map->playerY = 0;
	map->player_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	
	
	if (argc != 2 || strstr(argv[1], ".ber") == NULL)
		handle_error("Invalid arguments",-1);
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		handle_error("Memory allocation failed",-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error("File could not be opened",-1);
	ft_init(map);
	get_map(fd, map);
	close(fd);
	check_map(map);
	map->mlx_ptr = mlx_init();
	// print_map(map);
	mlx_loop(map->mlx_ptr);
	system("leaks so_long");
	free_map(map);
	return (0);
}
