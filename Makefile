NAME = so_long
CC = gcc
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS = 
OBJS := $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR) 
	make -C $(LIBFTDIR) 
	$(CC) $(FLAGS) $(NAME).c $(OBJS) $(LIBFT)  -o $(NAME)

clean: $(OBJS) 
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re: fclean all