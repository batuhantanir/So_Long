

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		width;
	int		height;
	int 	playerX;
	int 	playerY;
	int 	player_count;
	int 	collectible_count;
	int 	exit_count;
}			t_map;

typedef struct s_point
{
	int x;
	int y;
}			t_point;

void		print_map(t_map *map);
void		free_map(t_map *map);
void		get_map(int fd, t_map *map);
void		*my_realloc(void *ptr, size_t size);
void		check_map(t_map *map);
void		handle_error(char *message,int err_no);
void	flood_fill(char **area, t_point size, t_point begin);
void	check_flood_fill_map(t_map *area);
#endif