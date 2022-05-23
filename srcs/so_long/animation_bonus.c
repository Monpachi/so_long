#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	animated_fog(t_map *map)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	while (g_fog[i])
	{
		map->fog[i] = ft_lstadd_back(&map, ft_lstnewvoid(mlx_xpm_file_to_image(map->mlx,
						(char *)g_fog[i], &width, &height)));
		i++;
	}
}
