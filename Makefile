# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:56:48 by jaacosta          #+#    #+#              #
#    Updated: 2024/10/23 18:00:42 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS =	control_hexa.c \
	control_basics.c \
	control_voidptr.c \
	control_unsignedint.c \
	ft_printf.c 

HEADER = ft_printf.h

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) ft_printf.h
		$(AR) $(NAME) $(OBJS)

%.o: %.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) $(OBS)

re:	
		$(RM) $(NAME) $(OBJS)
		make all

.PHONY: all, clean, fclean, re
