#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	init_struct(t_map *map, char **line, char **argv)
{
	map->fullmap = line;
	map->lenght = ft_strlen(line[0]);
	map->win_choice = NULL;
	map->movement = NULL;
	map->move_step = 0;
	map->move_count = 0;
	map->height = check_width(argv);
}

void	space(t_map *map)
{
	if (map->win_choice == NULL)
	{
		mlx_clear_window(map->mlx, map->win);
		map->win_choice = ft_strdup("space");
		game(map);
	}
}


int	escape(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	return (EXIT_SUCCESS) ;
}
