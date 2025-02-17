# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 22:40:07 by abelov            #+#    #+#              #
#    Updated: 2025/02/17 22:40:17 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= account

CFLAGS 			:= -Wall -Wextra -Werror -std=c++98
CC 				= c++

SRC 			= tests.cpp Account.cpp
BUILD_DIR		= build
OBJS			= $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ) -o $(name)

%.o: %.cpp
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(name)

re: fclean all

.PHONY: all clean fclean re

