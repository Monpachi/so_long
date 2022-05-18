#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	which_wall(t_map *map, int y, int x, char **line)
{
	if (y == 0 && x == 0 && line[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall0,
			(64 * x), (64 * y));
	else if (y == 0 && x < map->lenght - 1 && x > 0 && line[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall1,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == 0 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall2,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 && x == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->wall7,
			(64 * x), (64 * y));
	else if (line[y][x] && y > 0 && y < map->height - 1 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall3,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x == map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall4,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x > 0 &&
			x < map->lenght - 1)
		mlx_put_image_to_window(map->mlx, map->win, map->wall5,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y == map->height - 1 && x == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->wall6,
			(64 * x), (64 * y));
}

void	wall_middle1(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] != '1' &&
		line[y - 1][x] != '1' && line[y][x + 1] != '1' &&
		line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall8,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] != '1' && line[y][x - 1] == '1'
		&& line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall17,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y][x + 1] == '1' && line[y - 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall20,
			(64 * x), (64 * y));
}

void	wall_middle2(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line [y - 1][x] == '1' && line[y][x - 1] == '1' &&
		line[y][x + 1] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall21,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y][x + 1] == '1' && line[y + 1][x] != '1' &&
		line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall12,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y + 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall13,
			(64 * x), (64 * y));
}

void	wall_middle3(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] == '1' && line[y - 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall18,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall19,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line[y + 1][x] == '1' && line[y][x - 1] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall14,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
		line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y + 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall15,
			(64 * x), (64 * y));
}

void	wall_middle4(t_map *map, int y, int x, char **line)
{
	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x + 1] == '1' &&
		line[y + 1][x] != '1' && line[y - 1][x] != '1' && line[y][x - 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall9,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
		line[y - 1][x] != '1' && line[y + 1][x] != '1' && line[y][x + 1] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall10,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
		line[y][x - 1] != '1' && line[y][x + 1] != '1' && line[y - 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall11,
			(64 * x), (64 * y));
	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
		line [y][x + 1] != '1' && line[y][x - 1] != '1' &&
		line[y + 1][x] != '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall16,
			(64 * x), (64 * y));
}


// void	wall_middle(t_map *map, int y, int x, char **line)
// {
// 	//wall center
// 	if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y + 1][x] != '1' &&
// 		line[y - 1][x] != '1' && line[y][x + 1] != '1' &&
// 		line[y][x - 1] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall8,
// 			(64 * x), (64 * y));

// 	//wall tri way top left right
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
// 		line[y + 1][x] != '1' && line[y][x - 1] == '1'
// 		&& line[y][x + 1] == '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall17,
// 			(64 * x), (64 * y));

// 	//wall tri way left bot right
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
// 		line[y][x - 1] == '1' && line[y][x + 1] == '1' && line[y - 1][x] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall20,
// 			(64 * x), (64 * y));

	// // wall allway
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
	// 	line [y - 1][x] == '1' && line[y][x - 1] == '1' &&
	// 	line[y][x + 1] == '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall21,
	// 		(64 * x), (64 * y));

	// //wall bot left
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
	// 	line[y][x + 1] == '1' && line[y + 1][x] != '1' &&
	// 	line[y][x - 1] != '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall12,
	// 		(64 * x), (64 * y));

	// //wall bot right
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
	// 	line[y][x - 1] == '1' && line[y + 1][x] != '1' && line[y][x + 1] != '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall13,
	// 		(64 * x), (64 * y));

	// //wall top right
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
	// 	line[y][x - 1] == '1' && line[y - 1][x] != '1' && line[y][x + 1] != '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall18,
	// 		(64 * x), (64 * y));

	// //wall top left
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
	// 	line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y][x - 1] != '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall19,
	// 		(64 * x), (64 * y));

	// //wall betweeen vertical
	// else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
	// 	x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
	// 	line[y + 1][x] == '1' && line[y][x - 1] != '1' && line[y][x + 1] != '1')
	// 	mlx_put_image_to_window(map->mlx, map->win, map->wall14,
	// 		(64 * x), (64 * y));

// 	//wall between horizontal
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
// 		line[y][x + 1] == '1' && line[y - 1][x] != '1' && line[y + 1][x] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall15,
// 			(64 * x), (64 * y));

// 	//wall right
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y][x + 1] == '1' &&
// 		line[y + 1][x] != '1' && line[y - 1][x] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall9,
// 			(64 * x), (64 * y));

// 	//wall left
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y][x - 1] == '1' &&
// 		line[y - 1][x] != '1' && line[y + 1][x] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall10,
// 			(64 * x), (64 * y));

// 	//wall top
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y + 1][x] == '1' &&
// 		line[y][x - 1] != '1' && line[y][x + 1] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall11,
// 			(64 * x), (64 * y));

// 	//wall bot
// 	else if (line[y][x] == '1' && y > 0 && y < map->height - 1 &&
// 		x > 0 && x < map->lenght - 1 && line[y - 1][x] == '1' &&
// 		line [y][x + 1] != '1' && line[y][x - 1] != '1')
// 		mlx_put_image_to_window(map->mlx, map->win, map->wall16,
// 			(64 * x), (64 * y));
// }
