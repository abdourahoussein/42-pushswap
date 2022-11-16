# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 06:07:01 by abhousse          #+#    #+#              #
#    Updated: 2022/11/16 06:07:02 by abhousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

HEADER = ft_printf.h

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	@ar -rcs $@ $^

all: $(NAME) 

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: clean fclean re
