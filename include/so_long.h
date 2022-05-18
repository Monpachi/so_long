#ifndef SO_LONG_H
# define    SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>

/******************************************************************************/
/*								IMG LOCATION								  */
/******************************************************************************/
# define IMG_PLAYER "./img/P.xpm"
# define IMG_EXIT "./img/E1.xpm"
# define IMG_ITEM "./img/CC.xpm"

/**************************/
/*			FLOOR		  */
/**************************/

# define IMG_BG	"./img/03.xpm"

/**************************/
/*			WALL		  */
/**************************/
# define IMG_WALL0 "./img/wall_top_left.xpm"
# define IMG_WALL1 "./img/wall_top.xpm"
# define IMG_WALL2 "./img/wall_top_right.xpm"
# define IMG_WALL3 "./img/wall_right.xpm"
# define IMG_WALL4 "./img/wall_bot_right.xpm"
# define IMG_WALL5 "./img/wall_bot.xpm"
# define IMG_WALL6 "./img/wall_bot_left.xpm"
# define IMG_WALL7 "./img/wall_left.xpm"
/****************/
/* center wall  */
/****************/
# define IMG_WALL8 "./img/wall_center.xpm"
# define IMG_WALL9 "./img/wall_center_right.xpm"
# define IMG_WALL10 "./img/wall_center_left.xpm"
# define IMG_WALL11 "./img/wall_center_top.xpm"
# define IMG_WALL16 "./img/wall_center_bot.xpm"
# define IMG_WALL12 "./img/wall_center_bot_left.xpm"
# define IMG_WALL13 "./img/wall_center_bot_right.xpm"
# define IMG_WALL14 "./img/wall_center_between.xpm"
# define IMG_WALL15 "./img/wall_center_between2.xpm"
# define IMG_WALL17 "./img/wall_center_tri1.xpm"
# define IMG_WALL18 "./img/wall_center_top_right.xpm"
# define IMG_WALL19 "./img/wall_center_top_left.xpm"
# define IMG_WALL20 "./img/wall_center_tri2.xpm"
# define IMG_WALL21 "./img/wall_center_allway.xpm"
# define IMG_WALL22 "./img/wall_center_tri3.xpm"
# define IMG_WALL23 "./img/wall_center_tri4.xpm"
# define IMG_WALL24 "./img/void.xpm"

# define WIDTH 64
# define HEIGHT 64

/******************************************************************************/
/*									Error									  */
/******************************************************************************/

# define MAP_OPEN "Error, your map is wide open\n"
# define MISSING_IMG "AN IMG IS MISSING\n"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct s_map
{
	int				height;
	int				lenght;
	void			*content;
	void			*next;
	int				number;
	void			*player;
	int				p_pos_x;
	int				p_pos_y;
	void			*exit;
	void			*wall0;
	void			*wall1;
	void			*wall2;
	void			*wall3;
	void			*wall4;
	void			*wall5;
	void			*wall6;
	void			*wall7;
	void			*wall8;
	void			*wall9;
	void			*wall10;
	void			*wall11;
	void			*wall12;
	void			*wall13;
	void			*wall14;
	void			*wall15;
	void			*wall16;
	void			*wall17;
	void			*wall18;
	void			*wall19;
	void			*wall20;
	void			*wall21;
	void			*wall22;
	void			*wall23;
	void			*wall24;
	void			*bg;
	void			*bg1;
	void			*enemy;
	void			*coll;
	int				collectible_nbr;
	int				game_score;
	void			*mlx;
	void			*win;
	char			**fullmap;
	int				move_count;
	int				move_step;
	int				myst_y;
	int				myst_x;
}	t_map;

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// }	t_mlx;

int		check_map_border(char **argv);
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
int		check_rectangle2(char **argv);
int		check_width(char **argv);
char	**putintab(char **argv);
void	wall_middle1(t_map *map, int y, int x, char **line);
void	wall_middle2(t_map *map, int y, int x, char **line);
void	wall_middle3(t_map *map, int y, int x, char **line);
void	wall_middle4(t_map *map, int y, int x, char **line);
void	which_wall(t_map *map, int y, int x, char **line);
void	waiting_to_mist(t_map *map, int y, int x);
/******************************************************************************/
/*									LIBFT									  */
/******************************************************************************/
int		init_img(int width, int height, char **line, int width_max);
t_map	*ft_lstnew(int number);
t_map	*ft_lstnewvoid(void *content);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
void	ft_lstclear(t_map **stack);
void		map_insert(t_map *map);
void	img_to_win(char **result, t_map *map);

int	key_hook(int keycode, t_map *map);
int	wall_block(t_map *map);
void	wall_to_win(t_map *map, int y, int x);
#endif
