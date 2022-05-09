#include "so_long.h"

t_map	*ft_lstnew(int number)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

t_map	*ft_lstlast(t_map *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_map **alst, t_map *new)
{
	t_map	*tmp;

	if (!*alst)
		*alst = new ;
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
	return ;
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

int	check(char **argv)
{
	t_map	*map_lenght;
	int		fd;
	char	*line;
	t_map	*tmp;

	map_lenght = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		printf("Map empty\n");
	printf("line = %s\n", line);
	while (line != NULL)
	{
		ft_lstadd_back(&map_lenght, ft_lstnew(ft_strlen(line)));
		line = get_next_line(fd);
	}
	tmp = map_lenght->next;
	while (map_lenght)
	{
		if (map_lenght->number != tmp->number)
			return (1);
		tmp = tmp->next;
	}
	close (fd);
	return (0);
}

