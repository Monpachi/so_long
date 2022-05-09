/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:37:36 by vchan             #+#    #+#             */
/*   Updated: 2022/05/09 18:02:19 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*get_next(char *tmp);
char	*get_line(char *str);
int		ft_strlen_until(char *str, char c);
char	*ft_strjoin(char *ret_value, char *buf);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);

#endif
