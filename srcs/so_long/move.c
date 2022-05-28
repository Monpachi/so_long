#include "so_long.h"
# include "../../minilibx-linux/mlx.h"
#include <limits.h>

void	player_mvt(t_map *map)
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
	waiting_to_mist(map);
	no_exit(map, fakey, fakex);
	rewrite_p(map, fakey, fakex);
	collision(map, fakey, fakex);
	enemy_mvt(map);
	update_struct(map, fakey, fakex);
}

void	player_down(t_map *map)
{
	if (map->fullmap[map->p_pos_y + 1][map->p_pos_x] != '1')
	{
		map->movement = DOWN_PLAYER;
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_up(t_map *map)
{
	if (map->fullmap[map->p_pos_y - 1][map->p_pos_x] != '1')
	{
		map->movement = UP_PLAYER;
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_left(t_map *map)
{
	if (map->fullmap[map->p_pos_y][map->p_pos_x - 1] != '1')
	{
		map->movement = LEFT_PLAYER;
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_right(t_map *map)
{
	if (map->fullmap[map->p_pos_y][map->p_pos_x + 1] != '1')
	{
		map->movement = RIGHT_PLAYER;
		collectible_hunter(map);
		player_mvt(map);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (map->stop == 0 && map->p_pos_x != 0 && map->p_pos_y != 0
		&& map->movement != GAME_OVER)
	{
		if (keycode == XK_s || keycode == XK_S)
			player_down(map);
		else if (keycode == XK_w || keycode == XK_W)
			player_up(map);
		else if (keycode == XK_a || keycode == XK_A)
			player_left(map);
		else if (keycode == XK_d || keycode == XK_D)
			player_right(map);
		if (map->movement == GAME_OVER)
			map->stop = 1;
	}
	if (keycode == XK_Escape)
		escape(map);
	if (keycode == XK_space && (map->movement != GAME_OVER && map->movement != IN_GAME))
		space(map);
	score_in_win(map);
	return (0);
}
