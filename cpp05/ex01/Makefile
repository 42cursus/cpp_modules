# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:27:11 by abelov            #+#    #+#              #
#    Updated: 2025/07/25 21:27:12 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= form

BUILD_DIR		= build
SRC_DIR			= src

MANDATORY_FLAGS	:= -Wall -Wextra -Werror -std=c++98 \
					-Wshadow -Woverloaded-virtual -Wstrict-aliasing=2
OPTIMIZE_FLAGS	:= -O0 -fasynchronous-unwind-tables
DEBUG_FLAGS		:= -g3 -gdwarf-3 \
					-fsanitize=address,undefined
INCLUDE_FLAGS	:= -I. -I./src -I$(INC_DIR) -I/usr/include

CFLAGS 			:= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS) \
                   					$(INCLUDE_FLAGS)
CPP 			= c++

_SRCS			= main.cpp \
					Form.cpp \
					Bureaucrat.cpp
SRCS			:= $(_SRCS:%=$(SRC_DIR)/%)

OBJS			= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CFLAGS) $(OBJS) -o $@
		@echo "$(NAME) BUILD COMPLETE!"

$(BUILD_DIR)/%.o: %.cpp
		@if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
		$(CPP) $(CFLAGS) -c $^ -o $@

## clean
clean:
		@$(RM) -rf $(OBJS)

## fclean
fclean: clean
		@$(RM) -vf $(NAME)

re: fclean all

.PHONY: all clean fclean re
