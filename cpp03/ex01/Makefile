# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 01:24:58 by abelov            #+#    #+#              #
#    Updated: 2025/03/17 01:24:58 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= scavTrap

CFLAGS 			:= -Wall -Wextra -Werror -std=c++98 -g3 -gdwarf-3 -O0 -fsanitize=address,undefined
CC 				= c++
RM				:= /bin/rm

SRCS			= main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp

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
