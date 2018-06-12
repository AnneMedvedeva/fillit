#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchernia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 02:02:07 by kchernia          #+#    #+#              #
#    Updated: 2017/12/22 21:09:22 by kchernia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = $(wildcard ./ft_*.c)
CFLAGS = -Wall -Wextra -Werror -I./

all : $(NAME)

$(NAME) : $(SRCS)
	@gcc -c $(CFLAGS) $^
	@ar crs $@ *.o

clean:
	@rm -f *.o
	@find . -type f -name "*~" -print -delete

fclean: clean
	@rm -f $(NAME)

re: fclean all
