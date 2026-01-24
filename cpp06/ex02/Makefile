# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 01:37:10 by abelov            #+#    #+#              #
#    Updated: 2026/01/21 01:37:10 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= identifier

BUILD_DIR		= build
SRC_DIR			= src

CPP 			= clang++
COMPILER		:= $(shell echo | $(CPP) -dM -E - | grep -q '__clang__' && echo clang || echo gcc)
OPTIMIZE_FLAGS	:= -O0 \
					-fasynchronous-unwind-tables \
 					-fno-omit-frame-pointer

ifeq ($(COMPILER),clang)
	OPTIMIZE_FLAGS	+= -fstandalone-debug \
						-Wglobal-constructors \
						-Wexit-time-destructors
else
	OPTIMIZE_FLAGS	+= -felide-constructors
endif

MANDATORY_FLAGS	:= -Wall -Wextra -Werror -std=c++98 \
					-Wshadow -Woverloaded-virtual -Wstrict-aliasing=2

DEBUG_FLAGS		:= -g3 -gdwarf-3 \
					-shared-libasan \
					-fsanitize=address,undefined \
					-fno-sanitize-recover=all
INCLUDE_FLAGS	:= -I. -I./src -I$(INC_DIR) -I/usr/include

CFLAGS 			:= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS) \
                   					$(INCLUDE_FLAGS)

SRC_DIR			= src
_SRCS			= \
					main.cpp \
					Base.cpp

SRCS			:= $(_SRCS:%=$(SRC_DIR)/%)

OBJS			= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CFLAGS) $(OBJS) -Wl,-rpath,/usr/lib/llvm-14/lib/clang/14.0.0/lib/linux -o $@
		@echo "$(NAME) BUILD COMPLETE!"
		#$(CPP) $(CFLAGS) $(OBJS) \
		# 			-Wl,-rpath,/usr/lib/llvm-14/lib/clang/14.0.0/lib/linux \
		# 			-shared-libasan \
		# 			-pthread
		# 			-Wl,-z,now -Wl,-z,relro -o $@

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

