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

// t_fog	*ft_lstnewvoid(void *fog)
// {
// 	t_fog	*str;

// 	str = malloc(sizeof(t_fog));
// 	if (!str)
// 		return (NULL);
// 	str->img_fog = fog;
// 		printf("fog=%p\n", fog);
// 	str->next = NULL;
// 	return (str);
// }

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

void	ft_lstclear(t_map **stack)
{
	t_map	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	return ;
}
/**********************************************************/

// void	ft_lstfog_back(t_fog **alst, t_fog *new)
// {
// 	t_fog	*tmp;

// 	if (!*alst)
// 		*alst = new ;
// 	else
// 	{
// 		tmp = ft_lstlastfog(*alst);
// 		tmp->next = new;
// 	}
// 	return ;
// }

// t_fog	*ft_lstlastfog(t_fog *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 	}
// 	return (lst);
// }
