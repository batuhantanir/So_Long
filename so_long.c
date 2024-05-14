/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:46 by btanir            #+#    #+#             */
/*   Updated: 2024/05/14 18:25:50 by btanir           ###   ########.fr       */
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
	check_map(&map);
	close(i);
	mlx_ptr = mlx_init();
	print_map(&map, mlx_ptr);
	mlx_loop(mlx_ptr);
	system("leaks so_long");
	free_map(&map);
	system("leaks so_long");
	return (0);
}
