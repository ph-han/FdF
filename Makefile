#-----------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

NAME		= fdf

INCLUDE		= -Iincludes -I./lib/mlx -I./lib/get_next_line -I./lib/libft

LIBFT_DIR	= ./lib/libft
LIBFT		= -L$(LIBFT_DIR) -lft

GNL_DIR		= ./lib/get_next_line
GNL			= -L$(GNL_DIR) -lgnl

MLX_DIR		= ./lib/mlx
MLX			= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCDIR = ./srcs
SRCS = check.c \
       color.c \
       draw.c \
       init.c \
       line_algo.c \
       main.c \
       move.c \
       parse.c \
       parse_utils.c \
       projection.c \
       rotate_map.c \
       rotate_metrix.c \
       scaling.c \
       utils.c \
       zoom.c
SRCS			:=	$(addprefix $(SRCDIR)/, $(SRCS))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@ $(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) -C $(MLX_DIR)
	@ echo $(GREEN)"- MLX complete" $(EOC)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ echo $(GREEN)"- LIBFT complete" $(EOC)
	@ $(MAKE) -C $(GNL_DIR)
	@ echo $(GREEN)"- GNL complete" $(EOC)
	@ $(CC) $(CFLAG) $(OBJS) $(LIBFT) $(GNL) $(MLX)  -o $(NAME)
	@ echo $(GREEN)"** FdF complete **" $(EOC)

clean:
	@ $(MAKE) -C $(GNL_DIR) clean
	@ echo $(GREEN)"- GNL cleaned" $(EOC)
	@ $(MAKE) -C $(LIBFT_DIR) clean
	@echo $(GREEN)"- LIBFT cleaned" $(EOC)
	@ $(MAKE) -C $(MLX_DIR) clean``
	@echo $(GREEN)"- MLX cleaned" $(EOC)
	@ rm -f $(OBJS)
	@echo $(GREEN)"** FdF clean done **" $(EOC)

fclean: clean
	@ $(MAKE) -C $(LIBFT_DIR) fclean
	@ $(MAKE) -C $(GNL_DIR) fclean
	@ rm -f $(NAME)
	@ echo $(GREEN)"** FdF fclean done **" $(EOC)

re: fclean all

.PHONY: all clean fclean re bonus
