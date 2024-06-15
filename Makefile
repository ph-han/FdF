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
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g3

DRAW_SRCS_DIR = ./srcs/draw
EVENT_SRCS_DIR = ./srcs/event
PARSE_SRCS_DIR = ./srcs/parse
UTILS_SRCS_DIR = ./srcs/utils

DRAW_SRCS = color.c \
       		draw.c\
	        line_algo.c

EVENT_SRCS = hook.c

PARSE_SRCS = parse.c \
			 parse_utils.c

UTILS_SRCS = check.c \
			 init.c \
			 move.c \
			 scaling.c \
			 zoom.c \
			 utils.c \
			 projection.c \
			 rotate_map.c \
			 rotate_metrix.c

SRCS			:= ./srcs/main.c
SRCS			+= $(addprefix $(DRAW_SRCS_DIR)/, $(DRAW_SRCS))
SRCS			+= $(addprefix $(EVENT_SRCS_DIR)/, $(EVENT_SRCS))
SRCS			+= $(addprefix $(PARSE_SRCS_DIR)/, $(PARSE_SRCS))
SRCS			+= $(addprefix $(UTILS_SRCS_DIR)/, $(UTILS_SRCS))



FILE_TOTAL = $(words $(SRCS))
COUNTER = 0

OBJS = $(SRCS:.c=.o)

all: $(NAME)

lib:
	@ $(MAKE) -C $(MLX_DIR)
	@ echo ""
	@ echo $(GREEN)"- MLX complete" $(EOC)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ echo ""
	@ echo $(GREEN)"- LIBFT complete" $(EOC)
	@ $(MAKE) -C $(GNL_DIR)
	@ echo ""
	@ echo $(GREEN)"- GNL complete" $(EOC)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAG) $(OBJS) $(LIBFT) $(GNL) $(MLX) -o $(NAME)
	@ echo ""
	@ echo $(GREEN)"** FdF complete **" $(EOC)

%.o: %.c | lib
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
	@$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@
	@$(eval PERCENT=$(shell echo $$(($(COUNTER) * 100 / $(FILE_TOTAL)))))
	@ printf "Compiling $< - $@ ($(PERCENT)%%) ["
	@ for (( i = 0; i < $(PERCENT) / 10 * 3; i++ )); do \
		  printf "="; \
	   done
	@ printf "] $(PERCENT)%%\r"

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

help:
	@echo "Usage:"
	@echo "  make       	: Build all targets"
	@echo "  make fclean	: Remove all built files & binary file"
	@echo ""
	@echo "Available targets:"
	@echo "  all		: Builds all targets"
	@echo "  lib		: Builds library targets"
	@echo "  clean		: Cleans up built files"
	@echo "  fclean 	: Remove all built files & binary file"
	@echo "  re  		: fclean & all"
	@echo ""

%:
	@echo "Error: Target '$@' not found."
	@echo ""
	@make help

.PHONY: all clean fclean re help lib
