# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moboustt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 19:12:03 by moboustt          #+#    #+#              #
#    Updated: 2019/12/15 21:50:33 by moboustt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- This is a MakeFile -*-
NAME= libftprintf.a
_CC= gcc
_CFLAGS=-Wall -g -Wextra -Werror
_SOURCES= ft_atoi.c ft_printf.c ft_strchr.c ft_strlen.c integers.c pointers.c string.c char.c ft_itoa.c ft_strdup.c get_flags.c printf_tools.c unsigned.c converter.c ft_strjoin.c hexa.c percent.c printf_tools2.c
_OBJ= *.o
all: $(NAME)

$(NAME): $(_SOURCES)
	@$(_CC) $(_CFLAGS) -c $(_SOURCES)
	@ar rc $(NAME) *.o

clean: 
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

fclean: clean
	@rm -rf $(NAME) *.a
	@echo "Makefile : Clean .a files..."

re: fclean all

