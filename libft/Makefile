# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 14:38:01 by cchekov           #+#    #+#              #
#    Updated: 2021/10/26 20:25:10 by cchekov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c		\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c	\
		ft_memcmp.c \
		ft_memchr.c ft_memccpy.c ft_memmove.c ft_memset.c ft_split.c	\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c	\
		ft_strchr.c	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c	\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
		
BONUS_FUNCS	= ft_lstdelone_bonus.c  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
              ft_lstlast_bonus.c ft_lstadd_back_bonus.c  \
              ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJS = $(patsubst %.c,%.o,$(FUNCS))
BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_FUNCS))
	
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o: %.c
	CC $(FLAGS) -c $< -o $@

bonus : $(OBJS) $(BONUS_OBJS) 
	ar rsc $(NAME) $(OBJS) $(BONUS_OBJS) 

clean : 
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re bonus