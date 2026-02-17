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

CPP 			= c++
CPP 			= clang++
COMPILER		:= $(shell echo | $(CPP) -dM -E - | grep -q '__clang__' && echo clang || echo gcc)
OPTIMIZE_FLAGS	:= -O0 \
					-fasynchronous-unwind-tables \
 					-fno-omit-frame-pointer
LINK_FLAGS		:=

ifeq ($(COMPILER),clang)
	# clang++ -print-search-dirs
	# clang++ --print-resource-dir
	# clang++ -print-file-name=libclang_rt.asan-x86_64.so
	# clang++ -v -### test.cpp 2>&1 | grep -E 'LIBRARY_PATH| -L'
	CLANG_RDIR	:= $(shell $(CPP) --print-resource-dir)
	ASAN_RPATH	:= $(CLANG_RDIR)/lib/linux
	LINK_FLAGS	+= -Wl,--enable-new-dtags \
					-Wl,-rpath,$(ASAN_RPATH) \
					-Wl,-z,now -Wl,-z,relro \
					-unwindlib=libgcc -rtlib=libgcc \
					-Wl,--no-as-needed -Wl,-l:libpthread.so.0 -Wl,--as-needed
#					-Wl,--push-state,--no-as-needed -pthread -Wl,--pop-state
	OPTIMIZE_FLAGS	+= -fstandalone-debug \
						-Wglobal-constructors \
						-Wexit-time-destructors \

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

CXXFLAGS 		:= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) \
 						$(OPTIMIZE_FLAGS) $(INCLUDE_FLAGS)

SRC_DIR			= src
_SRCS			= \
					main.cpp \
					Base.cpp

SRCS			:= $(_SRCS:%=$(SRC_DIR)/%)

OBJS			= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CXXFLAGS) $(OBJS) $(LINK_FLAGS) -o $@
		@echo "$(NAME) BUILD COMPLETE!"

$(BUILD_DIR)/%.o: %.cpp
		@if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
		$(CPP) $(CXXFLAGS) -c $^ -o $@

## clean
clean:
		@$(RM) -rf $(OBJS)

## fclean
fclean: clean
		@$(RM) -vf $(NAME)

re: fclean all

.PHONY: all clean fclean re

