# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:04:49 by vlenard           #+#    #+#              #
#    Updated: 2023/01/19 14:02:57 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = 	main.c sort3and5.c sort500.c operations_push.c operations_reverserotate.c operations_rotate.c operations_swap.c \
		utils_list.c utils.c utils_makeitbeautiful.c utils_sort500.c errorhandling.c 
OBJS = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT): 
		cd libft && make && make clean
n:
		norminette $(SRC) pushswap.h
v:
		./visualizer/build/bin/visualizer
clean :
		rm -f $(OBJS)
fclean : clean
		rm -f ./$(NAME)
re : fclean
		$(MAKE)
.PHONY: all, n, clean, fclean, re, $(LIBFT), $(NAME)