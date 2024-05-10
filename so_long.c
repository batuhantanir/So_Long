/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/10 18:36:33 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

void	*my_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size); // Yeni bellek alanı tahsisi
	if (!new_ptr)
	{
		printf("Yeniden boyutlandırma başarısız oldu!\n");
		free(ptr); // Eski bellek bloğunu serbest bırak
		exit(EXIT_FAILURE);
	}
	if (ptr)
	{
		// Eski verileri yeni bellek alanına kopyala
		memcpy(new_ptr, ptr, size);
		free(ptr); // Eski bellek bloğunu serbest bırak
	}
	return (new_ptr);
}

void	get_map(int fd, t_map *map)
{
	char	*line;
	int		ret;

	ret = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (ret == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (line == 0)
		{
			free(line);
			break ;
		}
		map->map = my_realloc(map->map, (map->height + 1) * sizeof(char *));
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0)
			map->width = ft_strlen(line);
	}
}

void	print_map(t_map *map, void *mlx_ptr)
{
	int		i;
	int		j;
	void	*window;
	void	*asd;

	i = 0;
	j = 0;
	window = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	while (i < map->height)
	{
		j = 0;
		while (j < map->width )
		{
			ft_printf("%c\n", map->map[i][j]);
			asd = mlx_new_image(mlx_ptr, 1920, 1080);
			mlx_put_image_to_window(mlx_ptr, window, asd, 0, 0);
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

int	main(int argc, char **argv)
{
	int		i;
	t_map	map;
	void	*mlx_ptr;

	if (argc != 2)
	{
		ft_printf("is executed as: “./so_long *.ber” \n");
		exit(1);
	}
	if (strstr(argv[1], ".ber") == NULL)
	{
		ft_printf("file extension must be '*.ber'\n");
		exit(1);
	}
	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		ft_printf("Error asd\n");
		return (1);
	}
	map.map = NULL;
	map.width = 0; 
	map.height = 0;
	get_map(i, &map);
	close(i);
	mlx_ptr = mlx_init();
	print_map(&map, mlx_ptr);
	mlx_loop(mlx_ptr);
	system("leaks so_long");
	free_map(&map);
	return (0);
}
