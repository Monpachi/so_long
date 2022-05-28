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
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TRI3],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] == '1' && line[y][x - 1] != '1'
		&& line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TRI4],
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

void	no_exit(t_map *map, int fakey, int fakex)
{
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'E' &&
		map->collectible_nbr == 0)
		escape(map);
	if (map->fullmap[map->p_pos_y][map->p_pos_x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
	else
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit_p,
			(64 * (map->p_pos_x + fakex)), (64 * (map->p_pos_y + fakey)));
	else
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (map->p_pos_x + fakex)), (64 * (map->p_pos_y + fakey)));
}

void	score_in_win(t_map *map)
{
	char	*tmp;

	if (map->p_pos_x != 0 && map->p_pos_y != 0)
	{
		tmp = ft_itoa(map->move_step);
		mlx_put_image_to_window(map->mlx, map->win, map->black, 0, 90);
		mlx_string_put(map->mlx, map->win, 10, 80, 0xccccff, "step :");
		mlx_string_put(map->mlx, map->win, 10, 100, 0xccccff, tmp);
		free(tmp);
		tmp = ft_itoa(map->collectible_nbr);
		mlx_put_image_to_window(map->mlx, map->win, map->black, 0, 120);
		mlx_string_put(map->mlx, map->win, 10, 130, 0xccccff, "kid(s):");
		mlx_string_put(map->mlx, map->win, 10, 150, 0xccccff, tmp);
		free(tmp);
	}
}
