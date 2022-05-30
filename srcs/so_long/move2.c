/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:12:03 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 14:41:50 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../../minilibx-linux/mlx.h"

void	player_mvt(t_map *map)
{
	int		fakey;
	int		fakex;

	fakey = 0;
	fakex = 0;
	if (map->movement == UP_PLAYER)
		fakey = -1;
	else if (map->movement == LEFT_PLAYER)
		fakex = -1;
	else if (map->movement == RIGHT_PLAYER)
		fakex = 1;
	else if (map->movement == DOWN_PLAYER)
		fakey = 1;
	waiting_to_mist(map);
	no_exit(map, fakey, fakex);
	rewrite_p(map, fakey, fakex);
	collision(map, fakey, fakex);
	update_struct(map, fakey, fakex);
	enemy_mvt(map);
}
