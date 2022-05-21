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
/*			INTRO		  */
/**************************/

# define IMG_INTRO "./img/intro/pennywise.xpm"
# define IMG_INTRO1 "./img/intro/newgame.xpm"
# define IMG_INTRO2 "./img/intro/pennylong.xpm"
# define IMG_INTRO3 "./img/intro/pennywisesmall.xpm"

/**************************/
/*			FLOOR		  */
/**************************/

# define IMG_BG	"./img/03.xpm"

/**************************/
/*		ANIMATION		  */
/**************************/

# define WIDTH 64
# define HEIGHT 64
# define WIDTH_INTRO 960
# define HEIGHT_INTRO 960
# define WIDTH_INTRO_SX 300
# define HEIGHT_INTRO_SY 325
# define WIDTH_INTRO_LX 200
# define HEIGHT_INTRO_LY 200
# define WIDTH_NEWGAME 165
# define HEIGHT_NEWGAME 54
# define WIN_X 650
# define WIN_Y 650


/******************************************************************************/
/*									Error									  */
/******************************************************************************/

# define MAP_OPEN "Error, your map is wide open\n"
# define MISSING_IMG "AN IMG IS MISSING\n"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef enum e_wall
{
	TOP_LEFT,
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOT_RIGHT,
	BOT,
	BOT_LEFT,
	LEFT,
	CENTER,
	CENTER_RIGHT,
	CENTER_LEFT,
	CENTER_TOP,
	CENTER_BOT,
	CENTER_BOT_LEFT,
	CENTER_BOT_RIGHT,
	CENTER_BETWEEN,
	CENTER_BETWEEN2,
	CENTER_TRI1,
	CENTER_TOP_RIGHT,
	CENTER_TOP_LEFT,
	CENTER_TRI2,
	CENTER_ALLWAY,
	CENTER_TRI3,
	CENTER_TRI4,
	VOID,
	NB_WALL
}	t_wall;

const static char *g_wall[NB_WALL] = {
	"./img/wall_top_left.xpm",
	"./img/wall_top.xpm",
	"./img/wall_top_right.xpm",
	"./img/wall_right.xpm",
	"./img/wall_bot_right.xpm",
	"./img/wall_bot.xpm",
	"./img/wall_bot_left.xpm",
	"./img/wall_left.xpm",
	"./img/wall_center.xpm",
	"./img/wall_center_right.xpm",
	"./img/wall_center_left.xpm",
	"./img/wall_center_top.xpm",
	"./img/wall_center_bot.xpm",
	"./img/wall_center_bot_left.xpm",
	"./img/wall_center_bot_right.xpm",
	"./img/wall_center_between.xpm",
	"./img/wall_center_between2.xpm",
	"./img/wall_center_tri1.xpm",
	"./img/wall_center_top_right.xpm",
	"./img/wall_center_top_left.xpm",
	"./img/wall_center_tri2.xpm",
	"./img/wall_center_allway.xpm",
	"./img/wall_center_tri3.xpm",
	"./img/wall_center_tri4.xpm",
	"./img/void.xpm"
};

typedef struct s_map
{
	int				height;
	int				lenght;
	void			*content;
	void			*next;
	int				number;
	void			*player;
	int				p_init_x;
	int				p_pos_x;
	int				p_pos_y;
	char			*movement;
	char			*win_choice;
	void			*exit;
	void			*intro;
	void			*intro1;
	void			*intro2;
	void			*intro3;
	void			*wall[25];
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
	void			*blackmamba;
}	t_map;

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
void	intro_window(t_map *map);
void	init_struct(t_map *map, char **line, char **argv);
/******************************************************************************/
/*									GAME									  */
/******************************************************************************/

void	collectible_hunter(t_map *map, int i);
int		player_left(t_map *map);
int		player_right(t_map *map);
int		player_down(t_map *map);
int		player_up(t_map *map);
void	space(t_map *map);
int		escape(t_map *map);
void	game(t_map *map);
/******************************************************************************/
/*									LIBFT									  */
/******************************************************************************/
int		init_img(int width, int height, char **line, int width_max);
t_map	*ft_lstnew(int number);
t_map	*ft_lstnewvoid(void *content);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
void	ft_lstclear(t_map **stack);
void	map_insert(t_map *map);
void	img_to_win(char **result, t_map *map);

int		key_hook(int keycode, t_map *map);
int		wall_block(t_map *map);
void	wall_to_win(t_map *map, int y, int x);
#endif
