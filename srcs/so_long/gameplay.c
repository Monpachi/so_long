#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	no_fog_exit(t_map *map)
{
	if (map->location_exit_x && map->location_exit_y)
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			64 * map->location_exit_x, 64 * map->location_exit_y);
}

void	waiting_to_mist(t_map *map)
{
	no_fog_exit(map);
	if (map->move_count == 0)
	{
		map->myst_y = map->p_pos_y;
		map->myst_x = map->p_pos_x;
		if (map->myst_x2 != 0 || map->myst_y2 != 0)
			mlx_put_image_to_window(map->mlx, map->win, map->fog,
				(64 * (map->myst_x2)), (64 * (map->myst_y2)));
	}
	else if (map->move_count == 1)
	{
		map->myst_y2 = map->p_pos_y;
		map->myst_x2 = map->p_pos_x;
		if (map->myst_x3 != 0 || map->myst_y3 != 0)
			mlx_put_image_to_window(map->mlx, map->win, map->fog,
				(64 * (map->myst_x3)), (64 * (map->myst_y3)));
		no_fog_exit(map);
	}
	else if (map->move_count == 2)
	{
		map->move_count = -1;
		mlx_put_image_to_window(map->mlx, map->win, map->fog,
			(64 * (map->myst_x)), (64 * (map->myst_y)));
		map->myst_x3 = map->p_pos_x;
		map->myst_y3 = map->p_pos_y;
	}
}

void	erase_collectible(t_map *map, int y, int x)
{
	int	i;

	i = 1;
	map->collectible_nbr -= i;
	map->fullmap[y][x] = '0';
	if (map->collectible_nbr == 0)
		destroy_img(map, map->coll);
}

void	collectible_hunter(t_map *map)
{
	int		fakey;
	int		fakex;

	fakey = 0;
	fakex = 0;
	if (map->movement == UP_PLAYER)
		fakey = -1;
	else if (map->movement == LEFT_PLAYER)
		fakex = -1;
	else if (map->movement == RIGHT_PLAYER)
		fakex = 1;
	else if (map->movement == DOWN_PLAYER)
		fakey = 1;
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'C')
		erase_collectible(map, map->p_pos_y + fakey,
			map->p_pos_x + fakex);
}

int	collision(t_map *map, int fakey, int fakex)
{
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'B' ||
		map->fullmap[map->p_pos_y][map->p_pos_x] == 'B')
	{
		mlx_clear_window(map->mlx, map->win);
		if ((map->lenght * 64) > WIN_X && (map->height * 64) > WIN_Y)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->game_over,
				(map->lenght * 32) - GAME_OVER_X / 2,
				(map->height * 32) - GAME_OVER_Y / 2);
		}
		else if ((map->lenght * 64) < WIN_X || (map->height * 64) > WIN_Y)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->game_over,
				(map->lenght * 32) - GAME_OVER_X / 2,
				(map->height * 32) - GAME_OVER_Y / 2);
		}
		else if ((map->lenght * 64) > WIN_X && (map->height * 64) < WIN_Y)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->game_over,
				(map->lenght * 32) - GAME_OVER_X / 2,
				(map->height * 32) - GAME_OVER_Y / 2);
		}
		map->movement = GAME_OVER;
	}
	return (0);
}
