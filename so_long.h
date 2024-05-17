

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	t_point	*player;
	t_point	*exit;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		moves;
}			t_map;

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define WALL '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define ELEMENTS "10CPE"

void		print_map(t_map *map);
void		free_map(t_map *map, int height);
void		get_map(int fd, t_map *map);
void		*my_realloc(void *ptr, size_t size);
void		check_map(t_map *map);
void		handle_error(char *message, int err_no, t_map *map);
void		flood_fill(char **area, t_point size, t_point begin);
void		check_flood_fill_map(t_map *area);
#endif