#include "so_long.h"
#include "../../minilibx-linux/mlx.h"

char	**putintab(char **argv)
{
	int		len;
	char	**result;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	len = check_width(argv);
	printf("%d\n", len);
	result = malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	result[i] = get_next_line(fd);
	i++;
	while (len > 0)
	{
		result[i] = get_next_line(fd);
		i++;
		len--;
	}
	close (fd);
	return (result);
}

void	wall_middle5(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] == '1' && line[y][x - 1] == '1'
		&& line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[22],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] == '1' && line[y][x - 1] != '1'
		&& line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[23],
			(64 * x), (64 * y));
}

void	wall_to_win(t_map *map, int y, int x)
{
	char	**line;

	line = map->fullmap;
	which_wall(map, y, x, line);
	wall_middle1(map, y, x, line);
	wall_middle2(map, y, x, line);
	wall_middle3(map, y, x, line);
	wall_middle4(map, y, x, line);
	wall_middle5(map, y, x, line);
}
