NAME = libftprintf.a

SRCS =	ft_printf.c ft_parse.c\
		ft_count_num.c ft_itoa.c\
		ft_print_hex.c ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_uint.c\
		ft_putchar.c ft_putstr.c
		

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rc ${NAME}

RM = rm -f

TEST = test.c

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIB} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

debug:
	${CC}  -g ${SRCS} ${TEST} && ./a.out

test: 
	${CC} test.c libftprintf.a && ./a.out
	
.PHONY: all clean fclean re debug test
