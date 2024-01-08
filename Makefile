NAME = cub3D

SRCS = srcs/main.c \
srcs/init.c \
srcs/check.c \
srcs/map.c \
srcs/utils.c \
srcs/mlx.c \
srcs/event.c \
srcs/ray.c \
srcs/moveset.c \
srcs/test.c \
srcs/screen.c \
srcs/flood_fill.c \
srcs/wall.c \

OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Wextra -Werror -g3

MLX = ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

RM = rm -rf

LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	$(CC) $(OBJS) $(MLX) $(LIB) -o $(NAME)


debug: $(OBJS)
	@make -C ./libft
	$(CC) -fsanitize=address $(OBJS) $(LIB) $(MLX) -o $(NAME)

clean:
	$(RM) $(LIB) $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all