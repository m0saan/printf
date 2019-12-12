# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moboustt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 19:12:03 by moboustt          #+#    #+#              #
#    Updated: 2019/12/06 22:26:56 by moboustt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- This is a MakeFile -*-
NAME= libftprintf.a
_CC= gcc
_CFLAGS=-Wall -g -Wextra -Werror
_SOURCES= *.c
_src= libft/*.o
_OBJ= *.o
all: $(NAME)

$(NAME): $(_SOURCES)
	@$(_CC) $(_CFLAGS) -c $(_SOURCES)
	@ar rc $(NAME) $(_src) *.o

clean: 
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

fclean: clean
	@rm -rf $(NAME) *.a
	@echo "Makefile : Clean .a files..."

re: fclean all

