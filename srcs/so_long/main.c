/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:10:39 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 17:46:28 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../../minilibx-linux/mlx.h"

int	close_win(t_map *map)
{
	escape(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map = (t_map){0};
	parsing(argc, argv, &map);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (1);
	intro_window(&map, argv);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 17, (1L << 17), close_win, &map);
	mlx_loop_hook(map.mlx, looking_for_animation, &map);
	mlx_loop(map.mlx);
	return (0);
}
