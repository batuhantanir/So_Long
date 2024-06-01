/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:36:18 by btanir            #+#    #+#             */
/*   Updated: 2024/06/01 12:33:24 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_map *map, int x, int y);

int	key_event(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(map, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(map, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(map, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(map, 1, 0);
	else if (keycode == KEY_ESC)
		close_window(map);
	ft_put_imgs(map);
	return (0);
}

static void	move_player(t_map *map, int x, int y)
{
	if (map->map[map->player.y + y][map->player.x + x] == '1')
		return ;
	if (map->exit.y == map->player.y + y && map->exit.x == map->player.x + x
		&& map->collectible_count == 0)
	{
		map->moves++;
		ft_printf("Moves: %d\nYou won!\n", map->moves);
		close_window(map);
	}
	if (map->map[map->player.y + y][map->player.x + x] == 'C')
	{
		map->map[map->player.y][map->player.x] = '0';
		map->collectible_count--;
	}
	if (map->map[map->player.y][map->player.x] != 'E')
		map->map[map->player.y][map->player.x] = '0';
	if (map->map[map->exit.y][map->exit.x] == '0')
		map->map[map->exit.y][map->exit.x] = 'E';
	map->player.x += x;
	map->player.y += y;
	map->map[map->player.y][map->player.x] = 'P';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}
