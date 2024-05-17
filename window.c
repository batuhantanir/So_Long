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
	(void)param;
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_W)
		printf("Yukarı\n");
	else if (keycode == KEY_S)
		printf("Aşağı\n");
	else if (keycode == KEY_A)
		printf("Sola\n");
	else if (keycode == KEY_D)
		printf("Sağa\n");
	else if (keycode == KEY_UP)
		printf("Yukarı\n");
	else if (keycode == KEY_DOWN)
		printf("Aşağı\n");
	else if (keycode == KEY_LEFT)
		printf("Sola\n");
	else if (keycode == KEY_RIGHT)
		printf("Sağa\n");
	return (0);
}
void	create_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		handle_error("mlx_init failed", -1, map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->width * 33, map->height
			* 33, "so_long");
	if (!map->mlx_win)
		handle_error("mlx_new_window failed", -1, map);
	mlx_hook(map->mlx_win, 17, 0, close_window, map);
	mlx_key_hook(map->mlx_win, key_event, map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	create_window(map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			// if (map->map[i][j] == WALL)
			// 	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
			// 		map->wall.img, j * 33, i * 33);
			j++;
		}
		i++;
	}
}
