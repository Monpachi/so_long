################################################################################
#                                     CONFIG                                   #
################################################################################
MAKEFLAGS += 	--silent
NAME		=	so_long
NAME_BONUS	=	bonus
RM			=	rm -f
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
LIB			=	-L./minilibx-linux -lmlx -lXext -lX11

################################################################################
#                          PROGRAM'S SRCS / OBJS                               #
################################################################################

SRCS		=	srcs/so_long/parsing_map.c \
				srcs/so_long/exit.c \
				srcs/so_long/check_ber.c \
				srcs/so_long/so_long_utilities.c \
				srcs/gnl/get_next_line.c \
				srcs/gnl/get_next_line_utils.c

OBJS		= 	$(SRCS:.c=.o)

SRC_SO_LONG	=	srcs/so_long/main.c
OBJS_SO_LONG=	$(SRC_SO_LONG:.c=.o)

INCLUDE		= -I ./include

all: $(NAME)

%.o:			%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

################################################################################
#                                 Makefile rules                               #
################################################################################


$(NAME):	$(OBJS) $(OBJS_SO_LONG)
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) || $(MAKE) $@

clean	:
	@$(RM) $(OBJS) $(OBJS_SO_LONG);

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

malloc_test: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} -L. -lmallocator

.PHONY: all clean fclean re
