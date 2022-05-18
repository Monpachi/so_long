#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	waiting_to_mist(t_map *map, int y, int x)
{
	char **line;

	line = map->fullmap;
	if (map->move_step == 0)
	{
		map->myst_y = y;
		map->myst_x = x;
		printf("line[y][x] = %c\n", line[y][x]);
	}
	if (map->move_step == 2)
	{
		printf("RESETH");
		map->move_step = 0;
		line[map->p_pos_y][map->p_pos_x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->wall24,
		 	(64 * (map->p_pos_x)), (64 * (map->p_pos_y - 2)));
		map->myst_y = y;
		map->myst_x = x;
	}
}

