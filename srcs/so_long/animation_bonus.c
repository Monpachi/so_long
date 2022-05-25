#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

// void	struct_animated_fog(t_map *map)
// {
// 	int		i;
// 	int		height;
// 	int		width;
// 	t_fog	*fog;
// 	t_fog	*begin;

// 	fog = NULL;
// 	i = 0;
// 	ft_lstfog_back(&fog, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx,
// 				(char *)g_fog[i++], &width, &height)));
// 	map->ptr_fog = fog;
// 	begin = fog;
// 	while (g_fog[i])
// 	{
// 		ft_lstfog_back(&fog, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx,
// 					(char *)g_fog[i], &width, &height)));
// 		i++;
// 	}
// 	ft_lstlastfog(fog)->next = begin;
// }

// void	struct_animated_p(t_map *map)
// {
// 	int		i;
// 	int		height;
// 	int		width;
// 	t_fog	*player;
// 	t_fog	*begin;

// 	player = NULL;
// 	i = 0;
// 	ft_lstfog_back(&player, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx, (char *)g_player[i++], &width, &height)));
// 	map->ptr_player = player;
// 	begin = player;
// 	while (g_player[i])
// 	{
// 		ft_lstfog_back(&player, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx,
// 					(char *)g_player[i], &width, &height)));
// 		i++;
// 	}
// 	ft_lstlastfog(player)->next = begin;
// }


// void	img_to_win3(char result, t_map *map, int y, int x)
// {
// 	if (result == 'P')
// 	{
// 		mlx_put_image_to_window(map->mlx, map->win, map->ptr_player->img_player,
// 			(64 * (x)), (64 * (y)));
// 		map->p_pos_x = x;
// 		map->p_pos_y = y;
// 	}
	// if (result == '0')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall[FOG],
	// 		(64 * x), (64 * y));
	// 	// mlx_put_image_to_window(map->mlx, map->win, map->ptr_fog->img_fog,
		// 	(64 * x), (64 * y));
	// if (result == 'E')
	// {
	// 	mlx_put_image_to_window(map->mlx, map->win, map->exit,
	// 		(64 * x), (64 * y));
	// 	map->location_exit_x = x;
	// 	map->location_exit_y = y;
	// }
	// if (result == 'C')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->coll,
	// 		(64 * x), (64 * y));
	// if (result == 'B')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->enemy,
	// 		(64 * x), (64 * y));
// }

void	fog_insert(t_map *map)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (i < NB_FOG)
	{
		map->fog[i] = mlx_xpm_file_to_image(map->mlx, (char *)g_fog[i],
				&width, &height);
		i++;
	}
}

void	player_animation(t_map *map)
{
	int	width;
	int	height;

	map->player1 = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER1,
			&width, &height);
	if (map->time > 1500)
		mlx_put_image_to_window(map->mlx, map->win, map->player1,
			(64 * map->p_pos_x), (64 * map->p_pos_y));
	if (map->time > 3000)
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * map->p_pos_x), (64 * map->p_pos_y));
}

void	fog_animation(t_map *map, int y, int x)
{
	if (map->time % 3000 == 0 && map->fullmap[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->fog[map->fog_changer],
			(64 * x), (64 * y));
	if (y == map->height - 1 && x == map->lenght - 1)
	{
		map->fog_changer++;
		if (map->fog_changer == NB_FOG)
			map->fog_changer = 0;
	}
}

int	looking_for_animation(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	if (!ft_strcmp(map->movement, "game_over") ||
		!ft_strcmp(map->movement, "intro"))
		return (0);
	map->time++;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == 'P')
				player_animation(map);
			fog_animation(map, y, x);
			if (map->time >= 6000)
				map->time = 0;
			x++;
		}
		y++;
	}
	return (0);
}

void	rewrite_p(t_map *map, int fakey, int fakex)
{
	map->fullmap[map->p_pos_y][map->p_pos_x] = '0';
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] != 'B')
	{
		map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] = 'P';
	}
}
