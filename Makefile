# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 12:03:30 by gmorange          #+#    #+#              #
#    Updated: 2021/09/08 15:51:38 by gmorange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=clang
CFLAGS=-Wall -Werror -Wextra
LIBS= -L ./libft/ -lft
SRCS=	./srcs/push_swap.c \
	./srcs/parsing.c \
	./srcs/operation.c \
	./srcs/push.c \
	./srcs/reverse_rotade.c \
	./srcs/rotade.c \
	./srcs/reverse_rotade_bis.c \
	./srcs/rotade_bis.c \
	./srcs/swap.c \
	./srcs/utils.c \
	./srcs/utils_rotation.c \
	./srcs/choose_best_a.c \
	./srcs/found_min_max.c \
	./srcs/three_five_sort.c \
	./srcs/perfect_spot.c

OBJS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: libft/libft.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

libft/libft.a:
	make -C ./libft/

clean :
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean:
	rm -rf $(NAME) $(OBJS)
	make fclean -C ./libft/

re: fclean all

.PHONY: all re clean fclean
