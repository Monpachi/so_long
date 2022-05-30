/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:12:46 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 16:37:44 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(char *line, char **argv, int width)
{
	int		i;
	int		width_max;

	i = 0;
	width_max = check_width(argv) - 1;
	while (line[i])
	{
		if (line[i] != '1' && (width == 0 || width == width_max))
			exit_failure_free(line, MAP_OPEN);
		else if ((line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			&& (width > '0' || width < width_max))
			exit_failure_free(line, MAP_OPEN);
		i++;
	}
	return (0);
}

int	check_map_border(char **argv)
{
	char	*line;
	int		fd;
	int		width;
	int		width_max;

	width = 0;
	width_max = check_width(argv);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_failure("Your map is VOIIIID\n");
	while (line != NULL)
	{
		check_border(line, argv, width);
		free (line);
		line = get_next_line(fd);
		width++;
	}
	free(line);
	close (fd);
	return (0);
}

int	all_element(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			map->nb_player++;
		if (line[i] == 'C')
			map->nb_collectible++;
		if (line[i] == 'E')
			map->nb_exit++;
		i++;
	}
	return (0);
}

int	check_characters(char **argv, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[++i] != '\0')
		{
			if (!line)
				exit_failure("error empty\n");
			if (line[i] != 'P' && line[i] != '1' && line[i] != '0'
				&& line[i] != 'C' && line[i] != 'E' && line[i] != 'B')
				exit_failure_free(line, "Your map is not parsed\n");
			all_element(line, map);
		}
		free (line);
		line = get_next_line(fd);
	}
	if (map->nb_player == 0 || map->nb_collectible == 0 || map->nb_exit == 0)
		exit_failure("Missing some elements in your game\n");
	close (fd);
	return (free(line), 0);
}

int	parsing(int argc, char **argv, t_map *map)
{
	if (!map_name_check(argc, argv))
	{
		ft_putstr_fd("not a valid type of map\n", 2);
		return (1);
	}
	else if (check_rectangle2(argv))
	{
		ft_putstr_fd("your map doesn't fit the condition\n", 2);
		return (1);
	}
	else if (check_characters(argv, map))
	{
		ft_putstr_fd("missing some elements in your map\n", 2);
		return (1);
	}
	else if (check_map_border(argv))
	{
		ft_putstr_fd("your map is wide open\n", 2);
		return (1);
	}
	return (0);
}
