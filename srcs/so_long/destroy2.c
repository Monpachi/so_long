/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:31:19 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 18:02:14 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../../minilibx-linux/mlx.h"

int	check_fail_img(t_map *map)
{
	if (!map->fog)
		return (1);
	if (!map->fog1)
		return (1);
	if (!map->player)
		return (1);
	if (!map->player1)
		return (1);
	if (!map->coll)
		return (1);
	if (!map->exit)
		return (1);
	if (!map->exit_p)
		return (1);
	if (!map->enemy)
		return (1);
	if (!map->black)
		return (1);
	if (!map->bg)
		return (1);
	if (!map->game_over)
		return (1);
	return (0);
}

void	destroy_fail_check(t_map *map)
{
	if (map->fog)
		mlx_destroy_image(map->mlx, map->fog);
	if (map->fog1)
		mlx_destroy_image(map->mlx, map->fog1);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	if (map->player1)
		mlx_destroy_image(map->mlx, map->player1);
	if (map->coll)
		mlx_destroy_image(map->mlx, map->coll);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->exit_p)
		mlx_destroy_image(map->mlx, map->exit_p);
	if (map->enemy)
		mlx_destroy_image(map->mlx, map->enemy);
	if (map->black)
		mlx_destroy_image(map->mlx, map->black);
	if (map->bg)
		mlx_destroy_image(map->mlx, map->bg);
	if (map->game_over)
		mlx_destroy_image(map->mlx, map->game_over);
}
