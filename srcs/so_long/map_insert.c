#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

#include<string.h>
// void	black(t_map *map)
// {
// 	map->blackmamba = mlx_new_image(map->mlx, 64, 64);
// 	//printf("%p\n", map->blackmamba);
// 	//bzero(map->blackmamba, 64*64*sizeof(int));
// }

// void	animated_torch(t_map *map)
// {

// }


int	check_img(t_map *map)
{
	int	i;

	i = 0;
	if (map->player == NULL || map->exit == NULL || map->bg == NULL
		|| map->coll == NULL)
	{
		ft_putstr_fd(MISSING_IMG, 1);
		return (EXIT_FAILURE);
	}
	while (map->wall[i])
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

	map->player = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &width, &height);
	map->coll = mlx_xpm_file_to_image(map->mlx, IMG_ITEM, &width, &height);
	map->exit = mlx_xpm_file_to_image(map->mlx, IMG_EXIT, &width, &height);
	map->bg = mlx_xpm_file_to_image(map->mlx, IMG_BG, &width, &height);
	// black(map);
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
		mlx_put_image_to_window(map->mlx, map->win, map->wall[VOID],
			(64 * x), (64 * y));
	if (result == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			(64 * x), (64 * y));
	if (result == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coll,
			(64 * x), (64 * y));
}

void	img_to_win(char **result, t_map *map)
{
	int		y;
	int		x;
	int		i;

	map->collectible_nbr = 0;
	i = 1;
	y = 0;
	while (result[y])
	{
		printf("%s\n", result[y]);
		x = 0;
		while (result[y][x])
		{
			wall_to_win(map, y, x);
			img_to_win2(result[y][x], map, y, x);
			printf("y = %d  x = %d\n", y, x);
			if (result[y][x] == 'C')
				map->collectible_nbr = i++;
			x++;
		}
		y++;
	}
	printf("%s\n", result[y]);
	printf("----------> map.collectible = %d\n", map->collectible_nbr);
	return ;
}

