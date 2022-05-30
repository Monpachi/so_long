/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:23:52 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 17:04:25 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../../minilibx-linux/mlx.h"

void	enemy_mvt2(t_map *map, int fakey, int fakex)
{
	if (map->fullmap[map->en_pos_y][map->en_pos_x] != 'E')
		map->fullmap[map->en_pos_y][map->en_pos_x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->fog,
		(64 * (map->en_pos_x)), (64 * (map->en_pos_y)));
	map->en_pos_y = map->en_pos_y + fakey;
	map->en_pos_x = map->en_pos_x + fakex;
	if (map->e_move_count >= 3)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->enemy,
			(64 * (map->en_pos_x)), (64 * (map->en_pos_y)));
		if (map->e_move_count > 4)
			map->e_move_count = 0;
		else
			map->e_move_count++;
	}
}

void	enemy_mvt(t_map *map)
{
	int	fakey;
	int	fakex;

	fakey = 0;
	fakex = 0;
	if (map->movement == UP_PLAYER)
		fakey = +1;
	else if (map->movement == LEFT_PLAYER)
		fakex = +1;
	else if (map->movement == RIGHT_PLAYER)
		fakex = -1;
	else if (map->movement == DOWN_PLAYER)
		fakey = -1;
	if (map->en_pos_y > 0 && map->en_pos_y < map->height - 1
		&& map->en_pos_x > 0 && map->en_pos_x < map->lenght - 1
		&& map->fullmap[map->en_pos_y + fakey][map->en_pos_x + fakex] != '1'
		&& (map->movement != GAME_OVER))
	{
		enemy_mvt2(map, fakey, fakex);
		if (map->fullmap[map->en_pos_y][map->en_pos_x] != 'E')
			map->fullmap[map->en_pos_y][map->en_pos_x] = 'B';
		if (map->en_pos_y == map->p_pos_y && map->en_pos_x == map->p_pos_x)
			collision(map, fakey, fakex);
		map->e_move_count++;
	}
}
