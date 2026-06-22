# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 17:03:17 by amoura-d          #+#    #+#              #
#    Updated: 2026/06/22 13:10:55 by amoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libftprintf.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
SRCS    := ft_printf.c ft_printf_utils.c
OBJS    := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re