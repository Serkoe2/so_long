NAME = so_long
FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS_PROD = -Wall -Wextra -Werror
FLAGS_DEV = -g  -fsanitize=address
INCLUDES =  mlx/libmlx.a libft/libft.a ft_printf/libftprintf.a
CC = CLANG
SRCS= src/so_long.c src/map.c gnl/get_next_line.c src/hooks.c src/analyze.c \
		 src/image.c src/render.c src/clean.c
OBJS = ${SRCS:.c=.o}
OBJS_FOLDER = objs/

$(NAME): all
all: $(OBJS)  LIBS
	$(CC) $(FLAGS_DEV) $(OBJS)  $(INCLUDES) $(FRAEMWORKS) -o $(NAME)

%.o: %.c 
	$(CC)  $(FLAGS_DEV) $(FLAGS_PROD) -c $< -o $@

LIBS:
	@make -C mlx all
	@make -C libft bonus
	@make -C ft_printf all


clean:
	@make -C mlx clean
	@make -C libft clean
	@make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re: all clean fclean re LIBS

