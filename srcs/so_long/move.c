#include "so_long.h"
# include "../../minilibx-linux/mlx.h"
#include <limits.h>

void	player_mvt(t_map *map)
{
	int		fakey;
	int		fakex;

	fakey = 0;
	fakex = 0;
	if (!ft_strcmp(map->movement, "up"))
		fakey = -1;
	else if (!ft_strcmp(map->movement, "left"))
		fakex = -1;
	else if (!ft_strcmp(map->movement, "right"))
		fakex = 1;
	else if (!ft_strcmp(map->movement, "down"))
		fakey = 1;
	waiting_to_mist(map);
	no_exit(map, fakey, fakex);
	collision(map, fakey, fakex);
	enemy_mvt(map);
	update_struct(map, fakey, fakex);
}

void	player_down(t_map *map)
{
	if (map->fullmap[map->p_pos_y + 1][map->p_pos_x] != '1')
	{
		map->movement = ft_strdup("down");
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_up(t_map *map)
{
	if (map->fullmap[map->p_pos_y - 1][map->p_pos_x] != '1')
	{
		map->movement = ft_strdup("up");
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_left(t_map *map)
{
	if (map->fullmap[map->p_pos_y][map->p_pos_x - 1] != '1')
	{
		map->movement = ft_strdup("left");
		collectible_hunter(map);
		player_mvt(map);
	}
}

void	player_right(t_map *map)
{
	if (map->fullmap[map->p_pos_y][map->p_pos_x + 1] != '1')
	{
		map->movement = ft_strdup("right");
		collectible_hunter(map);
		player_mvt(map);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (map->stop == 0 && map->p_pos_x != 0 && map->p_pos_y != 0
		&& ft_strcmp(map->movement, "game_over"))
	{
		if (keycode == XK_s || keycode == XK_S)
			player_down(map);
		else if (keycode == XK_w || keycode == XK_W)
			player_up(map);
		else if (keycode == XK_a || keycode == XK_A)
			player_left(map);
		else if (keycode == XK_d || keycode == XK_D)
			player_right(map);
		if (!ft_strcmp(map->movement, "game_over"))
			map->stop = 1;
	}
	if (keycode == XK_Escape)
		escape(map);
	if (keycode == XK_space)
		space(map);
	printf("MOVEMENT\n");
	printf("enemy pos y = %d\n", map->enemy_pos_y);
	printf("enemy pos x = %d\n", map->enemy_pos_x);
	printf("-----------------------------\n");
	printf("p pos y = %d\n", map->p_pos_y);
	printf("p pos x = %d\n", map->p_pos_x);
	printf("-----------------------------\n");
	score_in_win(map);
	return (0);
}
