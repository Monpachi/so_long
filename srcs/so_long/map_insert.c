#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

#include<string.h>

// void	black(t_map *map)
// {
// 	map->blackmamba = mlx_new_image(map->mlx, 32, 32);
// 	bzero(map->blackmamba, 32*32*sizeof(int));
// }


int	check_img(t_map *map)
{
	int	i;

	i = 0;
	if (map->player == NULL || map->exit == NULL || map->exit_p == NULL
		|| map->bg == NULL || map->coll == NULL)
	{
		ft_putstr_fd(MISSING_IMG, 1);
		return (EXIT_FAILURE);
	}
	while (g_wall[i])
		i++;
	if (i != NB_WALL)
	{
		ft_putstr_fd(MISSING_IMG, 1);
		return (EXIT_FAILURE);
	}
	return (0);
}

void	wall_insert(t_map *map)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (g_wall[i])
	{
		map->wall[i] = mlx_xpm_file_to_image(map->mlx,
				(char *)g_wall[i], &width, &height);
		i++;
	}
}

void	map_insert(t_map *map)
{
	int	width;
	int	height;
	int	game_over_x;
	int	game_over_y;

	map->player = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &width, &height);
	map->coll = mlx_xpm_file_to_image(map->mlx, IMG_ITEM, &width, &height);
	map->exit = mlx_xpm_file_to_image(map->mlx, IMG_EXIT, &width, &height);
	map->exit_p = mlx_xpm_file_to_image(map->mlx, IMG_EXIT_P, &width, &height);
	map->bg = mlx_xpm_file_to_image(map->mlx, IMG_BG, &width, &height);
	map->black = mlx_xpm_file_to_image(map->mlx, IMG_BLACK, &width, &height);
	map->enemy = mlx_xpm_file_to_image(map->mlx, IMG_ENEMY, &width, &height);
	map->player1 = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER1,
			&width, &height);
	map->fog = mlx_xpm_file_to_image(map->mlx, IMG_FOG, &width, &height);
	map->fog1 = mlx_xpm_file_to_image(map->mlx, IMG_FOG1, &width, &height);
	map->game_over = mlx_xpm_file_to_image(map->mlx, IMG_GAME_OVER,
			&game_over_x, &game_over_y);
	wall_insert(map);
	check_img(map);
}

void	img_to_win2(char result, t_map *map, int y, int x)
{
	if (result == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (x)), (64 * (y)));
		map->p_pos_x = x;
		map->p_pos_y = y;
	}
	if (result == '0')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->fog,
			(64 * x), (64 * y));
	}
	if (result == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			(64 * x), (64 * y));
		map->location_exit_x = x;
		map->location_exit_y = y;
	}
	if (result == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coll,
			(64 * x), (64 * y));
	if (result == 'B')
		mlx_put_image_to_window(map->mlx, map->win, map->enemy,
			(64 * x), (64 * y));
}

void	img_to_win(char **result, t_map *map)
{
	int		y;
	int		x;
	int		i;

	i = 1;
	y = 0;
	while (result[y])
	{
		x = 0;
		while (result[y][x])
		{
			wall_to_win(map, y, x);
			img_to_win2(result[y][x], map, y, x);
			x++;
		}
		y++;
	}
	free_useless(map);
	return ;
}
