#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	check_img(t_map *map)
{
	if (map->player == NULL || map->exit == NULL || map->bg == NULL
		|| map->coll == NULL || map->wall0 == NULL || map->wall1 == NULL
		|| map->wall2 == NULL || map->wall3 == NULL || map->wall4 == NULL
		|| map->wall5 == NULL || map->wall6 == NULL || map->wall7 == NULL
		|| map->wall8 == NULL || map->wall9 == NULL || map->wall10 == NULL
		|| map->wall11 == NULL || map->wall12 == NULL || map->wall13 == NULL
		|| map->wall14 == NULL || map->wall15 == NULL || map->wall16 == NULL
		|| map->wall17 == NULL || map->wall18 == NULL || map->wall19 == NULL
		|| map->wall20 == NULL || map->wall21 == NULL || map->wall22 == NULL
		|| map->wall23 == NULL || map->wall24 == NULL)
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

	map->wall0 = mlx_xpm_file_to_image(map->mlx, IMG_WALL0, &width, &height);
	map->wall1 = mlx_xpm_file_to_image(map->mlx, IMG_WALL1, &width, &height);
	map->wall2 = mlx_xpm_file_to_image(map->mlx, IMG_WALL2, &width, &height);
	map->wall3 = mlx_xpm_file_to_image(map->mlx, IMG_WALL3, &width, &height);
	map->wall4 = mlx_xpm_file_to_image(map->mlx, IMG_WALL4, &width, &height);
	map->wall5 = mlx_xpm_file_to_image(map->mlx, IMG_WALL5, &width, &height);
	map->wall6 = mlx_xpm_file_to_image(map->mlx, IMG_WALL6, &width, &height);
	map->wall7 = mlx_xpm_file_to_image(map->mlx, IMG_WALL7, &width, &height);
	map->wall8 = mlx_xpm_file_to_image(map->mlx, IMG_WALL8, &width, &height);
	map->wall9 = mlx_xpm_file_to_image(map->mlx, IMG_WALL9, &width, &height);
	map->wall10 = mlx_xpm_file_to_image(map->mlx, IMG_WALL10, &width, &height);
	map->wall11 = mlx_xpm_file_to_image(map->mlx, IMG_WALL11, &width, &height);
	map->wall12 = mlx_xpm_file_to_image(map->mlx, IMG_WALL12, &width, &height);
	map->wall13 = mlx_xpm_file_to_image(map->mlx, IMG_WALL13, &width, &height);
	map->wall14 = mlx_xpm_file_to_image(map->mlx, IMG_WALL14, &width, &height);
	map->wall15 = mlx_xpm_file_to_image(map->mlx, IMG_WALL15, &width, &height);
	map->wall16 = mlx_xpm_file_to_image(map->mlx, IMG_WALL16, &width, &height);
	map->wall17 = mlx_xpm_file_to_image(map->mlx, IMG_WALL17, &width, &height);
}

void	map_insert(t_map *map)
{
	int	width;
	int	height;

	map->player = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &width, &height);
	map->coll = mlx_xpm_file_to_image(map->mlx, IMG_ITEM, &width, &height);
	map->exit = mlx_xpm_file_to_image(map->mlx, IMG_EXIT, &width, &height);
	map->bg = mlx_xpm_file_to_image(map->mlx, IMG_BG, &width, &height);
	wall_insert(map);
	map->wall18 = mlx_xpm_file_to_image(map->mlx, IMG_WALL18, &width, &height);
	map->wall19 = mlx_xpm_file_to_image(map->mlx, IMG_WALL19, &width, &height);
	map->wall20 = mlx_xpm_file_to_image(map->mlx, IMG_WALL20, &width, &height);
	map->wall21 = mlx_xpm_file_to_image(map->mlx, IMG_WALL21, &width, &height);
	map->wall22 = mlx_xpm_file_to_image(map->mlx, IMG_WALL22, &width, &height);
	map->wall23 = mlx_xpm_file_to_image(map->mlx, IMG_WALL23, &width, &height);
	map->wall24 = mlx_xpm_file_to_image(map->mlx, IMG_WALL24, &width, &height);
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
		mlx_put_image_to_window(map->mlx, map->win, map->wall24,
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

