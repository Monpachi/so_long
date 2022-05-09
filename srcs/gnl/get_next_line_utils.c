/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:59:48 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 16:25:11 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *ret_value, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!ret_value)
	{
		if (!*buf)
			return (NULL);
		return (ft_strdup(buf));
	}
	new = malloc(sizeof(char) * ((ft_strlen(ret_value) + ft_strlen(buf)) + 1));
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	if (ret_value)
		while (ret_value[++i] != '\0')
			new[i] = ret_value[i];
	while (buf[j] != '\0')
		new[i++] = buf[j++];
	new[ft_strlen(ret_value) + ft_strlen(buf)] = '\0';
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
