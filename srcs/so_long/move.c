#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	player_mvt(t_map *map, char **line)
{
	int		fakey;
	int		fakex;

	fakey = 0;
	fakex = 0;
	mlx_put_image_to_window(map->mlx, map->win, map->bg,
		(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
	if (!ft_strcmp(map->movement, "up"))
		fakey = -1;
	else if (!ft_strcmp(map->movement, "left"))
		fakex = -1;
	else if (!ft_strcmp(map->movement, "right"))
		fakex = 1;
	else if (!ft_strcmp(map->movement, "down"))
		fakey = 1;
	mlx_put_image_to_window(map->mlx, map->win, map->player,
		(64 * (map->p_pos_x + fakex)), (64 * (map->p_pos_y + fakey)));
	if (line[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'E' &&
		map->collectible_nbr == 0)
		escape(map);
	map->p_pos_y = map->p_pos_y + fakey;
	map->p_pos_x = map->p_pos_x + fakex;
	map->move_count++;
	map->move_step++;
}

int	player_down(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y + 1][map->p_pos_x] != '1')
	{
		map->movement = ft_strdup("down");
		collectible_hunter(map, i);
		player_mvt(map, line);
		printf("map mvt = %s\n", map->movement);
	}
	return (0);
}

int	player_up(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (map->p_pos_y > 0 && line[map->p_pos_y - 1][map->p_pos_x] != '1')
	{
		map->movement = ft_strdup("up");
		collectible_hunter(map, i);
		player_mvt(map, line);
		printf("map mvt = %s\n", map->movement);
	}
	return (0);
}

int	player_left(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y][map->p_pos_x - 1] != '1')
	{
		map->movement = ft_strdup("left");
		collectible_hunter(map, i);
		player_mvt(map, line);
		printf("map mvt = %s\n", map->movement);
	}
	return (0);
}

int	player_right(t_map *map)
{
	char	**line;
	int		i;

	i = 1;
	line = map->fullmap;
	if (line[map->p_pos_y][map->p_pos_x + 1] != '1')
	{
		map->movement = ft_strdup("right");
		collectible_hunter(map, i);
		player_mvt(map, line);
		printf("map mvt = %s\n", map->movement);
	}
	return (0);
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
	else if (keycode == XK_Escape)
		escape(map);
	else if (keycode == XK_space)
		space(map);
	}
	printf("------------------\n");
	printf("map item = %d\n", map->collectible_nbr);
//	printf("------------------------score  = %d\n", map->game_score);
//	printf("------------------------move_count = %d\n", map->move_count);
	printf("move_step = %d\n", map->move_step);
	// printf("map player pos x = %d\n", map->p_pos_x);
	// printf("map player pos y = %d\n", map->p_pos_y);
	return (0);
}
