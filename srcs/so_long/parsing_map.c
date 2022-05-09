#include "so_long.h"

int	check_first_and_last(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			exit_failure_free(line, "Error, your map is wide open, dumbass\n");
		i++;
	}
	free (line);
	return (0);
}

int	check_map_border(int argc, char **argv)
{
	char	*tmp;
	char	*line;
	int		len;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_failure_free(line, "Your map is VOIIIID\n");
	check_first_and_last(line);
	tmp = get_next_line(fd);
	if (!tmp)
		exit_failure_free(tmp, "Your map is empty\n");
	while (tmp != NULL)
	{
		line = copy_line(tmp);
		if (!line)
			exit_failure_free(line, "Is your map's name Void?\n");
		len = ft_strlen(line) - 1;
		if (line[0] != '1' || line[len] != '1')
			exit_failure_free(line, "Error, your map is wide open, dumbass\n");
		tmp = get_next_line(fd);
		if (tmp)
			free (line);
	}
	check_first_and_last(line);
	close (fd);
	return (0);
}

//sans les printfs < 25 ligne
// si j'envoie .ber , je segfault
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

int	check_characters(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;
	char	*tmp;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	tmp = get_next_line(fd);
	line = copy_line(tmp);
	while (line != NULL)
	{
		printf("line = %s\n", line);
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != 'P' && line[i] != '1' && line[i] != '0'
				&& line[i] != 'C' && line[i] != 'E')
				exit_failure_free(line, "Your map is not parsed\n");
			i++;
		}
		free (line);
		tmp = get_next_line(fd);
		if (!tmp)
			free (tmp);
		line = copy_line(tmp);
	}
	free (tmp);
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
	else if (check_rectangle(argc, argv))
	{
		printf("not a rectangle\n");
		return (1);
	}
	else if (check_characters(argc, argv))
	{
		printf("map parsed no good\n");
		return (1);
	}
	else if (check_map_border(argc, argv))
	{
		printf("wide open\n");
		return (1);
	}
	return (0);
}
