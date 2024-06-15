NAME = libgnl.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

FILE_TOTAL = $(words $(SRCS))
COUNTER = 0

%.o: %.c
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
	@$(CC) $(CFLAG) -c $< -o $@
	@$(eval PERCENT=$(shell echo $$(($(COUNTER) * 100 / $(FILE_TOTAL)))))
	@ printf "Compiling $< - $@ ($(PERCENT)%%) ["
	@ for (( i = 0; i < $(PERCENT) / 10 * 3; i++ )); do \
		  printf "="; \
	   done
	@ printf "] $(PERCENT)%%\r"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(SRCS_BN:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
