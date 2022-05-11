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


//sans les printfs < 25 ligne
/*
int	check_rectangle(int argc, char **argv)
{
	int		fd;
	int		len;
	int		width;
	char	*line;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_failure("Error, your map is empty\n");
	printf("line = %s\n", line);
	i = 0;
	len = ft_strlen(line) - 2;
	width = -1;
	while (line != NULL && line[i] != '\0')
	{
		i = ft_strlen(line) - 2;
		if (i != len)
			exit_failure_free(line, "Error, the map size is wrong bro\n");
		width++;
		free (line);
		line = get_next_line(fd);
		printf("line = %s\n", line);
	}
	printf("width = %d\n", width);
	if (width < 2 || len < 2 || width == len)
		exit_failure_free(line, "Error, the map size is wrong bro\n");
	return (0);
}
*/

int	check_characters(char **argv)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (!line)
				exit_failure("error empty\n");
			if (line[i] != 'P' && line[i] != '1' && line[i] != '0'
				&& line[i] != 'C' && line[i] != 'E')
				exit_failure_free(line, "Your map is not parsed\n");
			i++;
		}
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (!map_name_check(argc, argv))
	{
		printf("not a valid type of map\n");
		return (1);
	}
	else if (check_rectangle2(argv))
	{
		printf("not a rectangle\n");
		return (1);
	}
	else if (check_characters(argv))
	{
		printf("map parsed no good\n");
		return (1);
	}
	else if (check_map_border(argv))
	{
		printf("wide open\n");
		return (1);
	}
	return (0);
}

