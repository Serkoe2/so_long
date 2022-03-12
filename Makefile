NAME = so_long
#FRAEMWORKS = -Lmlx -lmlx -framework OpenGL -framework AppKit
FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS_PROD = -Wall -Wextra -Werror
FLAGS_DEV = -g -Wall -Wextra -Werror
SRCS =  src/game.c src/frame.c src/geometry.c src/hooks.c src/init.c src/map.c src/view_tools.c \
		src/get_next_line.c
INCLUDES = libft/libft.a ft_printf/libftprintf.a
CC = GCC
OBJS = ${SRCS:.c=.o}

SRCS_1 = src_1/so_long.c src_1/map.c src_1/get_next_line.c src_1/hooks.c src_1/analyze.c \
		 src_1/image.c src_1/render.c

OBJS_1 = ${SRCS_1:.c=.o}

# 	$(CC) $(OBJS) $(INCLUDES) $(FRAEMWORKS_OLD) -o $(NAME)
all: $(SRCS) $(OBJS) LIBS
	$(CC) -fsanitize=address $(OBJS) mlx/libmlx.a libft/libft.a  ft_printf/libftprintf.a $(FRAEMWORKS) -o $(NAME)

test: $(SRCS_1) $(OBJS_1) LIBS
	$(CC) -fsanitize=address $(OBJS_1) mlx/libmlx.a libft/libft.a  ft_printf/libftprintf.a $(FRAEMWORKS) -o $(NAME)

# $(CC) $(FLAGS_DEV)  -Imlx -c $< -o $@
%.o: %.c
	$(CC) $(FLAGS_DEV) -c $< -o $@

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

re: all clean fclean LIBS

