NAME=game
FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
SRC=src/*.c
GNL=gnl/*.c
INCLUDES=minilibx/libmlx.a libft/libft.a
CC = clang

all: $(SRC) $(GNL)
	@make -C minilibx all
	@make -C libft bonus
	$(CC) -g $(SRC) $(GNL) -o $(NAME) $(INCLUDES) $(FRAEMWORKS)

gnl_test: test.c $(GNL)
	$(CC) -g $(GNL) test.c -o gnl_test $(INCLUDES)
clean:
	@make -C minilibx clean

fclean: clean
	rm -f $(NAME)

push:
	git add .
	git status
	git commit -m update
	git push

re: all clean fclean push

