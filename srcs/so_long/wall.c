#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	which_wall(t_map *map, int y, int x, char **line)
{
	if (y == 0 && x == 0 && line[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[TOP_LEFT],
			(64 * x), (64 * y));
	else if (y == 0 && x < map->lenght - 1 && x > 0 && line[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[TOP],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == 0 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[TOP_RIGHT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 && x == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[LEFT],
			(64 * x), (64 * y));
	else if (line[y][x] && y > 0 && y < map->height - 1 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[RIGHT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[BOT_RIGHT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x > 0 &&
			x < map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[BOT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->wall[BOT_LEFT],
			(64 * x), (64 * y));
}

void	wall_middle1(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] != '1' &&
		line[y - 1][x] != '1' && line[y][x + 1] != '1' &&
		line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] != '1' && line[y][x - 1] == '1'
		&& line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TRI1],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y][x + 1] == '1' && line[y - 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TRI2],
			(64 * x), (64 * y));
}

void	wall_middle2(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line [y - 1][x] == '1' && line[y][x - 1] == '1' &&
		line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_ALLWAY],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y][x + 1] == '1' && line[y + 1][x] != '1' &&
		line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_BOT_LEFT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y + 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_BOT_RIGHT],
			(64 * x), (64 * y));
}

void	wall_middle3(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y - 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TOP_RIGHT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TOP_LEFT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] == '1' && line[y][x - 1] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_BETWEEN],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
		line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y + 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_BETWEEN2],
			(64 * x), (64 * y));
}

void	wall_middle4(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x + 1] == '1' &&
		line[y + 1][x] != '1' && line[y - 1][x] != '1' && line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_RIGHT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
		line[y - 1][x] != '1' && line[y + 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_LEFT],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] != '1' && line[y][x + 1] != '1' && line[y - 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_TOP],
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line [y][x + 1] != '1' && line[y][x - 1] != '1' &&
		line[y + 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[CENTER_BOT],
			(64 * x), (64 * y));
}
