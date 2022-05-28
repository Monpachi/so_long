#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	destroy_img_intro(t_map *map)
{
	mlx_destroy_image(map->mlx, map->intro1);
	mlx_destroy_image(map->mlx, map->intro);
}

void	free_intro_escape(t_map *map)
{
	int	y;

	y = 0;
	destroy_img_intro(map);
	while (map->fullmap[y])
	{
		free(map->fullmap[y]);
		y++;
	}
	free(map->fullmap);
}

void	free_useless(t_map *map)
{
	int	i;

	i = 0;
	while (i < NB_WALL)
	{
		mlx_destroy_image(map->mlx, map->wall[i]);
		i++;
	}
}

void	destroy_img(t_map *map, void *content)
{
	mlx_destroy_image(map->mlx, content);
}

void	free_game(t_map *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (map->fullmap[y])
	{
		free(map->fullmap[y]);
		y++;
	}
	free(map->fullmap[y]);
	free(map->fullmap);
	mlx_destroy_image(map->mlx, map->fog);
	mlx_destroy_image(map->mlx, map->fog1);
	mlx_destroy_image(map->mlx, map->player);
	mlx_destroy_image(map->mlx, map->player1);
	mlx_destroy_image(map->mlx, map->coll);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->exit_p);
	mlx_destroy_image(map->mlx, map->enemy);
	mlx_destroy_image(map->mlx, map->black);
	mlx_destroy_image(map->mlx, map->bg);
	mlx_destroy_image(map->mlx, map->game_over);
}

void	space(t_map *map)
{
	if (map->win_choice == 0)
	{
		mlx_clear_window(map->mlx, map->win);
		destroy_img_intro(map);
		map->win_choice = SPACE;
		game(map);
	}
}

int	escape(t_map *map)
{
	mlx_loop_end(map->mlx);
	if (map->movement == INTRO)
		free_intro_escape(map);
	if (map->movement != INTRO || map->movement == GAME_OVER)
		free_game(map);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit (EXIT_SUCCESS);
}
