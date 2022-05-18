#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	player_down(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y + 1][map->p_pos_x] != '1')
	{
		if (line[map->p_pos_y + 1][map->p_pos_x] == 'C')
			map->collectible_nbr -= i;
		line[map->p_pos_y + 1][map->p_pos_x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
		 	(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
		mlx_put_image_to_window(map->mlx, map->win, map->player,
		 	(64 * (map->p_pos_x)), (64 * (map->p_pos_y + 1)));
		waiting_to_mist(map, map->p_pos_y, map->p_pos_x);
		map->p_pos_y = map->p_pos_y + 1;
		map->move_count += i;
		map->move_step += i;
	}
}

void	player_up(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y - 1][map->p_pos_x] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y - 1)));
		map->p_pos_y = map->p_pos_y - 1;
		map->move_count += i;
	}
}

void	player_left(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y][map->p_pos_x - 1] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (map->p_pos_x - 1)), (64 * (map->p_pos_y)));
		map->p_pos_x = map->p_pos_x - 1;
		map->move_count += i;
	}
}

void	player_right(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y][map->p_pos_x + 1] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (map->p_pos_x + 1)), (64 * (map->p_pos_y)));
		map->p_pos_x = map->p_pos_x + 1;
		map->move_count += i;
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == XK_s || keycode == XK_S)
		player_down(map);
	else if (keycode == XK_w || keycode == XK_W)
		player_up(map);
	else if (keycode == XK_a || keycode == XK_A)
		player_left(map);
	else if (keycode == XK_d || keycode == XK_D)
		player_right(map);
//	printf("-----------------------map item = %d\n", map->collectible_nbr);
//	printf("------------------------score  = %d\n", map->game_score);
//	printf("------------------------move_count = %d\n", map->move_count);
	printf("move_step = %d\n", map->move_step);
	printf("map player pos x = %d\n", map->p_pos_x);
	printf("map player pos y = %d\n", map->p_pos_y);
	return (0);
}
