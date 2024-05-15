/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/15 19:30:21 by btanir           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2 || strstr(argv[1], ".ber") == NULL)
	{
		ft_printf("is executed as: “./so_long *.ber” \n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error asd\n");
		return (1);
	}
	get_map(fd, &map);
	close(fd);
	check_map(&map);
	map.mlx_ptr = mlx_init();
	print_map(&map);
	mlx_loop(map.mlx_ptr);
	system("leaks so_long");
	free_map(&map);
	system("leaks so_long");
	return (0);
}
