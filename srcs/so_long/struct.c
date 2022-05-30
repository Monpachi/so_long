/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:13:20 by vchan             #+#    #+#             */
/*   Updated: 2022/05/28 04:13:20 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
