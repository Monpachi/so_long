#ifndef SO_LONG_H
# define    SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAP_OPEN "Error, your map is wide open\n"
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct s_map
{
	void			*next;
	int				number;
	void			*player;
	void			*exit;
	void			*wall;
	void			*bg;
	void			*enemy;
	void			*collectible;
	void			*game_score;
}	t_map;

int	check_map_border(char **argv);
char	*get_next_line(int fd);
char	exit_failure(char *s);
char	*ft_strdup( char *s);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
int		check_rectangle(int argc, char **argv);
char	*copy_line(char *line);
//int		check_characters(int argc, char **argv);
int		parsing(int argc, char **argv);
char	exit_failure_free(char *freethis, char *s);
char	exit_failure_free2(char *freethis, t_map **freethistoo, char *s);
int		map_name_check(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
int		check_characters(char **argv);
void	print_stack(t_map *list);
int	check_rectangle2(char **argv);
int	check_width(char **argv);

/******************************************************************************/
/*									LIBFT									  */
/******************************************************************************/

t_map	*ft_lstnew(int number);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
void	ft_lstclear(t_map **stack);



void	graphic(char **argv, int width_max);
#endif
