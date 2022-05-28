#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	enemy_mvt(t_map *map)
{
	int	fakey;
	int	fakex;

	fakey = 0;
	fakex = 0;
	if (map->movement == UP_PLAYER)
		fakey = +1;
	else if (map->movement == LEFT_PLAYER)
		fakex = +1;
	else if (map->movement == RIGHT_PLAYER)
		fakex = -1;
	else if (map->movement == DOWN_PLAYER)
		fakey = -1;
	if (map->enemy_pos_y > 0 && map->enemy_pos_y < map->height - 1
		&& map->enemy_pos_x > 0 && map->enemy_pos_x < map->lenght - 1
		&& map->fullmap[map->enemy_pos_y + fakey][map->enemy_pos_x + fakex] != '1'
		&& (map->movement != GAME_OVER))
	{
		map->fullmap[map->enemy_pos_y][map->enemy_pos_x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->fog,
			(64 * (map->enemy_pos_x)), (64 * (map->enemy_pos_y)));
		map->enemy_pos_y = map->enemy_pos_y + fakey;
		map->enemy_pos_x = map->enemy_pos_x + fakex;
		if (map->e_move_count >= 3)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->enemy,
				(64 * (map->enemy_pos_x)), (64 * (map->enemy_pos_y)));
			if (map->e_move_count > 4)
				map->e_move_count = 0;
			else
				map->e_move_count++;
		}
		map->fullmap[map->enemy_pos_y][map->enemy_pos_x] = 'B';
		map->e_move_count++;
	}
}
