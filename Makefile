# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 17:03:17 by amoura-d          #+#    #+#              #
#    Updated: 2026/06/16 17:09:19 by amoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

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