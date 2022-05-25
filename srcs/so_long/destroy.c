#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	destroy_img(t_map *map, void *content)
{
	mlx_destroy_image(map->mlx, content);
}

void	space(t_map *map)
{
	if (map->win_choice == NULL)
	{
		mlx_clear_window(map->mlx, map->win);
		destroy_img(map, map->intro);
		destroy_img(map, map->intro2);
		destroy_img(map, map->intro3);
		destroy_img(map, map->intro1);
		map->win_choice = ft_strdup("space");
		game(map);
	}
}

int	escape(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_loop_end(map->mlx);
	exit (EXIT_SUCCESS);
}

