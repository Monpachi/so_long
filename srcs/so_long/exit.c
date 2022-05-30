/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:31:35 by vchan             #+#    #+#             */
/*   Updated: 2022/05/30 12:31:36 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	exit_failure(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

char	exit_failure_free(char *freethis, char *s)
{
	free (freethis);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

char	exit_failure_free2(char *freethis, t_map **freethistoo, char *s)
{
	if (freethis)
		free (freethis);
	if (freethistoo)
		ft_lstclear(freethistoo);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}
