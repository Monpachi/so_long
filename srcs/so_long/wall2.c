#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	wall_middle6(t_map *map, int y, int x)
{
	if (y > 0 && y < map->height - 1 && x > 0 && x < map->lenght - 1
		&& map->fullmap[y][x] == '1' && map->fullmap[y][x - 1] != '1'
		&& map->fullmap[y][x + 1] == '1' && map->fullmap[y + 1][x] == '1'
		&& map->fullmap[y + 1][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[SQUARE_TOP_L],
			(64 * x), (64 * y));

	else if (y > 0 && y < map->height - 1 && x > 0 && x < map->lenght - 1
		&& map->fullmap[y][x] == '1' && map->fullmap[y][x - 1] == '1' &&
		map->fullmap[y + 1][x] == '1' && map->fullmap[y + 1][x - 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[SQUARE_TOP_R],
			(64 * x), (64 * y));

	else if (y > 0 && y < map->height - 1 && x > 0 && x < map->lenght - 1
		&& map->fullmap[y][x] == '1' && map->fullmap[y - 1][x] == '1' &&
		map->fullmap[y - 1][x - 1] == '1' && map->fullmap[y][x - 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[SQUARE_BOT_R],
			(64 * x), (64 * y));

	else if (y > 0 && y < map->height - 1 && x > 0 && x < map->lenght - 1
		&& map->fullmap[y][x] == '1' && map->fullmap[y][x + 1] == '1' &&
		map->fullmap[y - 1][x] == '1' && map->fullmap[y - 1][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall[SQUARE_BOT_L],
			(64 * x), (64 * y));
}

// void	wall_middle7(t_map *map, int y, int x)
// {
// 	if (y > 0 && y < map->height - 1 && x > 0 && x < map->lenght - 1
// 		&& map->fullmap[y][x] == '1' && map->fullmap[y][x - 1] == '1'
// 		&& map->fullmap[y][x + 1] == '1' && map->fullmap[y + 1][x] == '1'
// 		&& map->fullmap[y + 1][x + 1] == '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall[SQUARE_EXIT_T_L],
// 			(64 * x), (64 * y));
// }
