# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 00:05:30 by abelov            #+#    #+#              #
#    Updated: 2025/02/26 00:05:31 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= bsp

CFLAGS 			:= -Wall -Wextra -Werror -std=c++98 -g3 -gdwarf-3 -O0
CC 				= c++
RM				:= /bin/rm

SRCS			= main.cpp \
					Fixed.cpp \
					FixedSSE.cpp \
					FixedX87.cpp \
					Point.cpp \
					bsp.cpp
BUILD_DIR		= build
OBJS			= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@
		@echo "$(NAME) BUILD COMPLETE!"

$(BUILD_DIR)/%.o: %.cpp
		@if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
		$(CC) $(CFLAGS) -c $^ -o $@

## clean
clean:
		@$(RM) -rf $(OBJS)

## fclean
fclean: clean
		@$(RM) -vf $(NAME)

re: fclean all

.PHONY: all clean fclean re


