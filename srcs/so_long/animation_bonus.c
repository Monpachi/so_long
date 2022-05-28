#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	player_animation(t_map *map)
{
	// int	width;
	// int	height;

	if (map->time > 400)
		mlx_put_image_to_window(map->mlx, map->win, map->player1,
			(64 * map->p_pos_x), (64 * map->p_pos_y));
	if (map->time > 1000)
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * map->p_pos_x), (64 * map->p_pos_y));
}

void	fog_animation(t_map *map, int y, int x)
{
	if (map->time % 550 == 0 && map->fullmap[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->fog,
			(64 * x), (64 * y));
	if (map->time % 800 == 0 && map->fullmap[y][x] == '0' )
		mlx_put_image_to_window(map->mlx, map->win, map->fog1,
			(64 * x), (64 * y));
}

int	looking_for_animation(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	if (map->movement == GAME_OVER || map->movement == INTRO)
		return (0);
	map->time++;
	if (map->time >= 1300)
		map->time = 0;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == 'P')
				player_animation(map);
			fog_animation(map, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	rewrite_p(t_map *map, int fakey, int fakex)
{
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] != 'B')
		map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] = 'P';
	else if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] != 'E')
		map->fullmap[map->p_pos_y][map->p_pos_x] = '0';
}
