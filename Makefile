# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:04:49 by vlenard           #+#    #+#              #
#    Updated: 2023/01/19 15:11:06 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = 	main.c sort/sort3and5.c sort/sort500.c operations/push.c operations/reverserotate.c operations/rotate.c operations/swap.c \
		utils/listutils.c utils/search.c utils/makeitbeautiful.c utils/sorthelper.c utils/errorhandling.c 
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
.PHONY: all, n, clean, fclean, re, v, $(LIBFT), $(NAME)