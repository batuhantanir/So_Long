/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:40:55 by btanir            #+#    #+#             */
/*   Updated: 2024/05/22 11:18:41 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_imgs
{
	void	*img_empty;
	void	*img_player;
	void	*img_1;
	void	*img_0;
	void	*img_collectible;
}			t_imgs;

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	t_point	player;
	t_point	exit;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		moves;
	t_imgs	imgs;
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
# define ELEMENTS_KEK "0CPE"

void		print_map(t_map *map);
void		free_map(t_map *map, int height);
void		get_map(int fd, t_map *map);
void		*my_realloc(void *ptr, size_t size);
void		check_map(t_map *map);
void		handle_error(char *message, int err_no, t_map *map);
void		flood_fill(t_map *map, t_point *begin);
void		check_flood_fill_map(t_map *area);
void		move_player(t_map *map, int x, int y);
void		ft_put_imgs(t_map *state);
int			ft_custom_strlen(char *str);
int			close_window(t_map *map);
void		ft_init_images(t_map *state);
void		create_window(t_map *map);
void		ft_init(t_map *map);
int			key_event(int keycode, void *param);
int			check_map_name(char *map_name);
int			main(int argc, char **argv);
void		add_line(t_map *map, char *line);
void		check_width(char *line, t_map *map);
void		player_exit_position(t_map *map, char *line);
#endif