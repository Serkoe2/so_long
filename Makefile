NAME = game
FRAEMWORKS_OLD = -Lmlx -lmlx -framework OpenGL -framework AppKit
FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS_PROD = -Wall -Wextra -Werror
FLAGS_DEV = -g -Wall -Wextra -Werror
SRCS =  src/frame.c src/game.c  src/geometry.c src/hooks.c src/init.c src/map.c \
			src/view_tools.c gnl/get_next_line_utils.c gnl/get_next_line.c
SRCS_OLD =  src/game.c  \
		gnl/get_next_line_utils.c gnl/get_next_line.c
INCLUDES = libft/libft.a ft_printf/libftprintf.a
CC = GCC
OBJS = ${SRCS:.c=.o}

# 	$(CC) $(OBJS) $(INCLUDES) $(FRAEMWORKS_OLD) -o $(NAME)
all: $(SRCS) $(OBJS) LIBS
	$(CC) $(OBJS) mlx/libmlx.a $(INCLUDES) $(FRAEMWORKS) -o $(NAME)

# $(CC) $(FLAGS_DEV)  -Imlx -c $< -o $@
%.o: %.c
	$(CC) $(FLAGS_DEV)  -c $< -o $@

#$(CC) test.o -Lmlx -lmlx mlx/libmlx.a $(FRAEMWORKS) -o test
test: test.c gnl/get_next_line_utils.o gnl/get_next_line.o test.o LIBS
	$(CC) test.o gnl/get_next_line_utils.o gnl/get_next_line.o mlx/libmlx.a libft/libft.a $(FRAEMWORKS) -o test

test_clean:
	rm -f test.o
	
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

push:
	git add .
	git status
	git commit -m update
	git push

re: all clean fclean push LIBS

