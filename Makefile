NAME = so_long
CC = gcc
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = minilibx
MLX = $(MLXDIR)/libmlx.a
SRCS = 
OBJS := $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR) 
	make -C $(LIBFTDIR) 
	make -C $(MLXDIR)
	$(CC) $(FLAGS) $(NAME).c $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS)  -o $(NAME)

clean: $(OBJS) 
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re: fclean all