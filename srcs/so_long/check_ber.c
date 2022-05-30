/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:06:36 by vchan             #+#    #+#             */
/*   Updated: 2022/05/28 04:06:37 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ber_strcpy(char *dest, char *src)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (src[i] != '.')
	{
		i++;
		if (src[i] == '\0')
			exit_failure("Error, not a valid a map\n");
	}
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j++] = '\0';
	return (dest);
}

int	map_name_check(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (argc == 2)
	{
		str = malloc(sizeof(char) * (4 + 1));
		str = ber_strcpy(str, argv[1]);
		if (!ft_strcmp(str, ".ber"))
			return (free (str), 1);
		else
			exit_failure_free(str, "Error, not a valid a map\n");
	}
	else
		exit_failure("bad input, it's not gonna work without the map\n");
	free (str);
	return (0);
}
