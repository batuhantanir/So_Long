NAME = so_long
CC = gcc
PRINTF = ./printf
SRCS = asd.c  get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF)
	$(CC) $(FLAGS) $(NAME).c $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(PRINTF)

fclean:clean
	rm -rf $(NAME)
	make fclean -C $(PRINTF)

re: fclean all