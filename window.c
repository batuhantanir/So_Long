#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

int	close_window(t_map *map)
{
	free_map(map, map->height);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}

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

void	ft_init_images(t_map *state)
{
	int	x;
	int	y;

	state->imgs.img_P = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/player1.xpm", &x, &y);
	if (!state->imgs.img_P)
		handle_error("textures/player1.xpm' file cannot be found", -1, state);
	state->imgs.img_E = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/exit.xpm", &x, &y);
	if (!state->imgs.img_E)
		handle_error("textures/exit.xpm' file cannot be found", -1, state);
	state->imgs.img_C = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/diamond.xpm", &x, &y);
	if (!state->imgs.img_C)
		handle_error("textures/diamond.xpm' file cannot be found", -1, state);
	state->imgs.img_0 = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/floor.xpm", &x, &y);
	if (!state->imgs.img_0)
		handle_error("textures/floor.xpm' file cannot be found", -1, state);
	state->imgs.img_1 = mlx_xpm_file_to_image(state->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	if (!state->imgs.img_1)
		handle_error("textures/wall.xpm' file cannot be found", -1, state);
}

static void	ft_put_img(t_map *state, char c, int x, int y)
{
	mlx_put_image_to_window(state->mlx_ptr, state->mlx_win, state->imgs.img_0,
		x, y);
	if (c == 'P')
	{
		if (state->exit.y == state->player.y
			&& state->exit.x == state->player.x)
			mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
				state->imgs.img_E, x, y);
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_P, x, y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_E, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(state->mlx_ptr, state->mlx_win,
			state->imgs.img_C, x, y);
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
void	move_player(t_map *map, int x, int y)
{
	if (map->map[map->player.y + y][map->player.x + x] == '1')
		return ;
	if (map->exit.y == map->player.y + y && map->exit.x == map->player.x + x
		&& map->collectible_count == 0)
	{
		ft_printf("You won!\n");
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

void	print_map(t_map *map)
{
	create_window(map);
	ft_init_images(map);
	ft_put_imgs(map);
	mlx_loop(map->mlx_ptr);
}
