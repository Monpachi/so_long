/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:37:05 by vchan             #+#    #+#             */
/*   Updated: 2022/05/11 13:01:22 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*forupdate_buff(char *buff, int len, int i)
{
	char	*tmp;
	int		k;
	int		j;

	tmp = malloc(sizeof(char) * (len - i + 1));
	if (!tmp)
		return (NULL);
	j = i++ + 1;
	while (buff[i])
	{
		tmp[i - j] = buff[i];
		if (buff[i++] == '\n')
		{
			k = j;
			while (k <= len)
			{
				buff[k - j] = buff[k];
				k++;
			}
			break ;
		}
	}
	tmp[i - j] = '\0';
	return (tmp);
}

char	*update_buff(char *buff, int len)
{
	int		i;

	i = 0;
	if (buff)
	{
		while (buff[i] && buff[i] != '\n')
			i++;
		if (!buff[i] || !buff[i + 1])
			return (NULL);
		return (forupdate_buff(buff, len, i));
	}
	return (NULL);
}

char	*readline(int fd, char *ret_value, char *buff)
{
	int		read_value;

	read_value = 1;
	while (!ft_strchr(ret_value, '\n') && read_value != 0)
	{
		read_value = read(fd, buff, BUFFER_SIZE);
		if (read_value == -1)
			return (NULL);
		buff[read_value] = '\0';
		ret_value = ft_strjoin(ret_value, buff);
	}
	return (ret_value);
}

char	*get_line(char *ret_value)
{
	char	*line;
	int		i;
	int		lb_at_end;

	i = 0;
	if (!ret_value)
		return (NULL);
	while (ret_value[i] != '\n' && ret_value[i])
		i++;
	lb_at_end = ret_value[i] == '\n';
	line = malloc(sizeof(char) * (i + 1 + lb_at_end));
	if (!line)
		return (NULL);
	i = 0;
	while (ret_value[i] != '\n' && ret_value[i])
	{
		line[i] = ret_value[i];
		i++;
	}
	if (ret_value[i++] == '\n')
		line[i - 1] = '\n';
	line[i - !lb_at_end] = '\0';
	free(ret_value);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*ret_value;

	ret_value = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	ret_value = update_buff(buff, ft_strlen(buff));
	if (ft_strchr(ret_value, '\n') != NULL)
		return (ret_value);
	ret_value = readline(fd, ret_value, buff);
	if (!ret_value)
		return (NULL);
	ret_value = get_line(ret_value);
	ret_value = copy_line(ret_value);
	return (ret_value);
}
