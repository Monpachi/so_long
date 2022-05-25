#ifndef SO_LONG_H
# define    SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <limits.h>

/******************************************************************************/
/*								IMG LOCATION								  */
/******************************************************************************/
# define IMG_PLAYER "./img/P.xpm"
# define IMG_PLAYER1 "./img/P1.xpm"
# define IMG_EXIT "./img/E1.xpm"
# define IMG_EXIT_P "./img/E.xpm"
# define IMG_ITEM "./img/CC.xpm"
# define IMG_BLACK "./img/black.xpm"
# define IMG_BLACK64 "./img/black64.xpm"
# define IMG_ENEMY "./img/enemy.xpm"
# define IMG_GAME_OVER "./img/game_over/game_over.xpm"

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
# define GAME_OVER_X 410
# define GAME_OVER_Y 410
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
	FOG,
	SQUARE_TOP_L,
	SQUARE_TOP_R,
	SQUARE_BOT_R,
	SQUARE_BOT_L,
	NB_WALL
}	t_wall;

typedef enum e_fog
{
	FOG0,
	FOG1,
	FOG2,
	FOG3,
	FOG4,
	FOG5,
	FOG6,
	FOG7,
	FOG8,
	NB_FOG
}	t_fog_nbr;

typedef enum e_player
{
	P,
	P1,
	NB_PLAYER
}	t_player_nbr;

static const char *g_player[NB_PLAYER] = {
	"./img/P.xpm"
	"./img/P1.xpm"
};

static const char *g_fog[NB_FOG] = {
	"./img/fog.xpm",
	"./img/fog1.xpm",
	"./img/fog2.xpm",
	"./img/fog3.xpm",
	"./img/fog4.xpm",
	"./img/fog5.xpm",
	"./img/fog6.xpm",
	"./img/fog7.xpm",
	"./img/fog8.xpm",
};

static const char *g_wall[NB_WALL] = {
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
	"./img/fog.xpm",
	"./img/square_top_left.xpm",
	"./img/square_top_right.xpm",
	"./img/square_bot_right.xpm",
	"./img/square_bot_left.xpm",
};

typedef struct s_fog
{
	struct s_fog	*next;
	void			*img_fog;
	void			*img_player;
} t_fog;

typedef struct s_map
{
	int				height;
	int				lenght;
	void			*content;
	struct s_map	*next;
	t_fog			*ptr_player;
	t_fog			*ptr_fog;
	int				number;
	void			*player;
	void			*player1;
	int				p_init_x;
	int				p_pos_x;
	int				p_pos_y;
	int				e_move_count;
	char			*movement;
	char			*win_choice;
	void			*exit;
	void			*exit_p;
	int				location_exit_x;
	int				location_exit_y;
	void			*intro;
	void			*intro1;
	void			*intro2;
	void			*intro3;
	void			*black;
	void			*black64;
	void			*fog[10];
	void			*wall[31];
	void			*bg;
	void			*enemy;
	int				enemies;
	int				enemy_pos_x;
	int				enemy_pos_y;
	void			*coll;
	int				collectible_nbr;
	void			*mlx;
	void			*win;
	char			**fullmap;
	int				move_count;
	int				move_step;
	int				stop;
	int				myst_y;
	int				myst_x;
	int				myst_y2;
	int				myst_x2;
	int				myst_y3;
	int				myst_x3;
	void			*game_over;
	int				time;
	int				fog_changer;
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
void	intro_window(t_map *map);
void	init_struct(t_map *map, char **line, char **argv);
void	no_exit(t_map *map, int fakey, int fakex);
void	wall_middle6(t_map *map, int y, int x);
void	wall_middle7(t_map *map, int y, int x);
void	destroy_img(t_map *map, void *content);
void	update_struct(t_map *map, int fakey, int fakex);
/******************************************************************************/
/*									GAME									  */
/******************************************************************************/

void	collectible_hunter(t_map *map);
void	player_left(t_map *map);
void	player_right(t_map *map);
void	player_down(t_map *map);
void	player_up(t_map *map);
void	space(t_map *map);
int		escape(t_map *map);
void	game(t_map *map);
void 	score_in_win(t_map *map);
void	waiting_to_mist(t_map *map);
int	collision(t_map *map, int fakey, int fakex);
void	enemy_mvt(t_map *map);
void	img_to_win2(char result, t_map *map, int y, int x);
/******************************************************************************/
/*									LIBFT									  */
/******************************************************************************/
int		init_img(int width, int height, char **line, int width_max);
t_map	*ft_lstnew(int number);
t_fog	*ft_lstnewvoid(void *content);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
void	ft_lstclear(t_map **stack);
char	*ft_itoa(int n);
void	ft_lstfog_back(t_fog **alst, t_fog *new);
t_fog	*ft_lstlastfog(t_fog *lst);

void	map_insert(t_map *map);
void	img_to_win(char **result, t_map *map);
int		key_hook(int keycode, t_map *map);
int		wall_block(t_map *map);
void	wall_to_win(t_map *map, int y, int x);

void	black(t_map *map);
void	animated_fog(void *arg);
int 	animation(t_map *map);
void	struct_animated_fog(t_map *map);
void	rewrite_p(t_map *map, int fakey, int fakex);
void	img_to_win3(char result, t_map *map, int y, int x);
void	struct_animated_p(t_map *map);
int	looking_for_animation(t_map *map);
void	fog_insert(t_map *map);

#endif

