/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:29:21 by btanir            #+#    #+#             */
/*   Updated: 2024/06/01 12:47:59 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

void	*my_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
	{
		ft_printf("reallocation failed!\n");
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

void	free_map(t_map *map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map->map[i]);
		free(map->map_copy[i]);
		i++;
	}
	free(map->map);
	free(map->map_copy);
}

void	handle_error(char *message, int err_no, t_map *map)
{
	ft_printf("Error: %s\n", message);
	free_map(map, map->height);
	exit(err_no);
}

int	ft_custom_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	close_window(t_map *map)
{
	ft_printf("Exit game!\n");
	free_map(map, map->height);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}
