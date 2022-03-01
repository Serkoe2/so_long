NAME=game
FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=
SRC=src/*.c
GNL=gnl/*.c
INCLUDES=minilibx/libmlx.a libft/libft.a ft_printf/libftprintf.a
CC = clang

all: $(SRC) $(GNL)
	@make -C minilibx all
	@make -C libft bonus
	@make -C ft_printf all
	$(CC) -g $(FLAGS) $(SRC) $(GNL) -o $(NAME) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C minilibx clean
	@make -C libft clean
	@make -C ft_printf clean

fclean: clean
	rm -f $(NAME)

push:
	git add .
	git status
	git commit -m update
	git push

re: all clean fclean push

