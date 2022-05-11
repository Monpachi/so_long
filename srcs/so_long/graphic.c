#include "so_long.h"

void	graphic(char **argv, int width_max)
{
	int		fd;
	char	*line;
	int		i;
	t_map	*map;
	int		width;

	width = 0;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[i] == '1')
			ft_lstadd_back(&map->wall, ft_lstnew(line));
	}
	return ;
}
