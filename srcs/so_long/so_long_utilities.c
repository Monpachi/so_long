#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
	{
		return (1);
	}
	if (s1[i] < s2[i])
	{
		return (-1);
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
}

void	print_stack(t_map *list)
{
	printf("----==== PRINT STACK ====----\n");
	while (list)
	{
		printf("%d\n", list->number);
		list = list->next;
	}
	printf("-----------------------------\n");
}

int	tothebackslash(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*copy_line(char *line)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	newline = malloc(sizeof(char) * (tothebackslash(line) + 1));
	if (!newline)
		return (free (line), NULL);
	while (j < tothebackslash(line))
	{
		newline[j] = line[i];
		j++;
		i++;
	}
	newline[j] = '\0';
	free (line);
	return (newline);
}
