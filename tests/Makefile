# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 10:30:00 by oyagci            #+#    #+#              #
#    Updated: 2017/05/12 17:20:54 by oyagci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= tests.out
CC					= clang
CFLAGS				= -Wall -Wextra -Werror

SOURCES				= test_main.c test_lexer.c test_quote.c
INCLUDES			= -I ../includes/ -I ../libft/includes -L ../libft -lft

TSRCS				= ../sources/lexer/*.c

all:
	$(CC) $(SOURCES) -o $(NAME) -lcheck -I /Users/oyagci/.brew/include -L /Users/oyagci/.brew/lib $(INCLUDES) $(TSRCS);
