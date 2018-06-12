#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvedi <amedvedi@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 02:02:07 by amedvedi          #+#    #+#              #
#    Updated: 2018/01/29 14:03:42 by amedvedi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./ -I./libft/

NAME = fillit
SRCS = $(wildcard ./*.c)
OBJS = $(SRCS:.c=.o)

LIB = ./libft/libft.a
LIB_SRCS = $(wildcard ./libft/*.c)

%.o: %.c
	@$(CC) -o $@ -c $^ $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@gcc -o $@ $^ $(CFLAGS)

$(LIB): $(LIB_SRCS)
	@$(MAKE) -C ./libft/ all

clean:
	@rm -f $(OBJS)
	@find . -type f -name "*~" -o -name "#*#" -delete
	@$(MAKE) -C ./libft/ clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean

re: fclean all
