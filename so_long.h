

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

void		print_map(t_map *map, void *mlx_ptr);
void		free_map(t_map *map);
void		get_map(int fd, t_map *map);
void		*my_realloc(void *ptr, size_t size);
void		check_map(t_map *map);

#endif