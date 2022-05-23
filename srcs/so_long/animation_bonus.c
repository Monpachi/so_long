#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	struct_animated_fog(t_map *map)
{
	int		i;
	int		height;
	int		width;
	t_fog	*fog = NULL;
	t_fog	*begin;

	i = 0;
	printf("g_fog[0] = %s\n", g_fog[0]);
	ft_lstfog_back(&fog, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx, (char *)g_fog[i++], &width, &height)));
		printf("fog=%p\n", fog->img_fog);
	map->ptr_fog = fog;
	begin = fog;
	while (g_fog[i])
	{
		ft_lstfog_back(&fog, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx,
					(char *)g_fog[i], &width, &height)));
		i++;
		printf("fog=%p\n", fog->img_fog);
	}
	ft_lstlastfog(fog)->next = begin;
	printf("fog=%p\n", fog->next->img_fog);

}

void	img_to_win3(char result, t_map *map, int y, int x)
{
	if (result == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			(64 * (x)), (64 * (y)));
		map->p_pos_x = x;
		map->p_pos_y = y;
	}
	if (result == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->ptr_fog->img_fog,
			(64 * x), (64 * y));
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

int animation(void *arg)
{
	int	y;
	int	x;
	t_map *map;

	map = (t_map *)arg;
	y = 0;
	while (map->fullmap[y])
	{
		x = 0;
		map->ptr_fog = map->ptr_fog->next;
		while (map->fullmap[y][x])
		{
			wall_to_win(map, y ,x);
			img_to_win3(map->fullmap[y][x], map, y, x);
			x++;
		}
	y++;
	}
	return (0);
}
