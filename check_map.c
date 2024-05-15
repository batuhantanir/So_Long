#include "libft/libft.h"
#include "so_long.h"


void	check_bottom(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' && *line == '\n')
		{
			ft_printf("invalid border\n");
			exit(-1);
		}
		line++;
	}
}

void	check_top(char *line)
{
	while (*line != '\0' && *line != '\n')
	{
		if (*line != '1')
		{
			ft_printf("invalid border\n");
			exit(-1);
		}
		line++;
	}
}

void	check_line(char *line, int width)
{
	if (line[0] != '1' || line[width - 2] != '1')
	{
		ft_printf("invalid map\n");
		exit(-1);
	}
}

void	check_middle(char **map, int height, int width)
{
	int	i;

	i = -1;
	while (++i < height - 1)
		check_line(map[i], width);
}

void	check_map(t_map *map)
{
	int		height;
	int		width;
	char	**matmap;

	height = map->height;
	width = map->width;
	matmap = map->map;
	if (height < 3 || width < 3)
	{
		ft_printf("invalid map\n");
		exit(-1);
	}
	check_top(matmap[0]);
	check_middle(matmap, height, width);
	check_bottom(matmap[height - 1]);
}
