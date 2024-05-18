/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:29:51 by btanir            #+#    #+#             */
/*   Updated: 2024/05/18 18:54:03 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "minilibx/mlx.h"

static void	ft_put_img(t_map *state, char c, int x, int y)
{
	mlx_put_image_to_window(state->mlx_ptr, state->mlx_win, state->imgs.img_0,
		x, y);
	if (c == 'P')
	{
		if (state->exit.y == state->player.y
			&& state->exit.x == state->player.x)
			mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
				state->imgs.img_empty, x, y);
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_player, x, y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_empty, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_collectible, x, y);
	else if (c == '0')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_0, x, y);
	else if (c == '1')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_1, x, y);
}

void	ft_put_imgs(t_map *state)
{
	int	h;
	int	w;

	h = 0;
	while (h < state->height)
	{
		w = 0;
		while (w < state->width)
		{
			ft_put_img(state, state->map[h][w], w * 64, h * 64);
			w++;
		}
		h++;
	}
}

void	ft_init_images(t_map *state)
{
	int	x;
	int	y;

	state->imgs.img_player = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/player.xpm", &x, &y);
	if (!state->imgs.img_player)
		handle_error("textures/player.xpm' file cannot be found", -1, state);
	state->imgs.img_empty = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/exit.xpm", &x, &y);
	if (!state->imgs.img_empty)
		handle_error("textures/exit.xpm' file cannot be found", -1, state);
	state->imgs.img_collectible = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/collectible.xpm", &x, &y);
	if (!state->imgs.img_collectible)
		handle_error("textures/collectible.xpm' file cannot be found", -1, state);
	state->imgs.img_0 = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/floor.xpm", &x, &y);
	if (!state->imgs.img_0)
		handle_error("textures/floor.xpm' file cannot be found", -1, state);
	state->imgs.img_1 = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	if (!state->imgs.img_1)
		handle_error("textures/wall.xpm' file cannot be found", -1, state);
}

void	create_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		handle_error("mlx_init failed", -1, map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->width * 64, map->height
			* 64, "so_long");
	if (!map->mlx_win)
		handle_error("mlx_new_window failed", -1, map);
	mlx_hook(map->mlx_win, 17, 0, close_window, map);
	mlx_key_hook(map->mlx_win, key_event, map);
}
