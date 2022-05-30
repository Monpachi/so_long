/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:06:43 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 17:08:27 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_width(char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_failure("your map doesn't exist");
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close (fd);
	return (i);
}

int	check_length(char *line, t_map *map_length)
{
	t_map	*tmp;

	tmp = map_length;
	while (tmp)
	{
		if (map_length->number != tmp->number)
			exit_failure_free2(line, &map_length,
				"the map is not in the right format\n");
		tmp = tmp->next;
	}
	return (0);
}

int	check_rectangle2(char **argv)
{
	int		width;
	t_map	*map_length;
	int		fd;
	char	*line;

	map_length = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_failure("Map empty\n");
	while (line != NULL)
	{
		ft_lstadd_back(&map_length, ft_lstnew(ft_strlen(line)));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_length(line, map_length);
	width = check_width(argv);
	if (width <= 2 || width == map_length->number || map_length->number <= 2)
		exit_failure_free2(line, &map_length,
			"the map is not in the right format\n");
	ft_lstclear(&map_length);
	close (fd);
	return (0);
}
