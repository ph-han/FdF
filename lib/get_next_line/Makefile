NAME = libgnl.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@ $(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(SRCS_BN:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
