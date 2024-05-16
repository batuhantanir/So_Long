#include "libft/libft.h"
#include "so_long.h"

void	handle_error(char *message, int err_no)
{
	ft_printf("%s\n", message);
	exit(err_no);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.x >= size.x)
		return ;
	if (area[begin.y][begin.x] == '1' || area[begin.y][begin.x] == 'F')
		return ;
	area[begin.y][begin.x] = 'F';
	begin.x++;
	if (begin.x < size.x && area[begin.y][begin.x] != '1')
		flood_fill(area, size, begin);
	begin.x -= 2;
	if (begin.x > 0 && area[begin.y][begin.x] != '1')
		flood_fill(area, size, begin);
	begin.x++;
	begin.y++;
	if (begin.y < size.y - 1 && area[begin.y][begin.x] != '1')
		flood_fill(area, size, begin);
	begin.y -= 2;
	if (begin.y > 0 && area[begin.y][begin.x] != '1')
		flood_fill(area, size, begin);
}

void	check_flood_fill_map(t_map *area)
{
	int i;
	int j;
	i = 0;

	while (i < area->height)
	{
		j = 0;
		while (area->map_copy[i][j] != '\0')
		{
			if (area->map_copy[i][j] == 'P')
				handle_error("Player is not surrounded by walls",-1);
			if (area->map_copy[i][j] == 'E')
				handle_error("Exit is not surrounded by walls",-1);
			if (area->map_copy[i][j] == 'C')
				handle_error("Collectible is not surrounded by walls",-1);
			j++;
		}
		i++;
	}
}