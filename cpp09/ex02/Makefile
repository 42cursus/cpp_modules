# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:46:33 by abelov            #+#    #+#              #
#    Updated: 2026/03/09 16:30:11 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= PmergeMe

BUILD_DIR		= build
SRC_DIR			= src

CPP 			= c++

COMPILER		:= $(shell echo | $(CPP) -dM -E - | grep -q '__clang__' && echo clang || echo gcc)
OPTIMIZE_FLAGS	:= -O0 \
					-fasynchronous-unwind-tables \
 					-fno-omit-frame-pointer
LINK_FLAGS		:=
SANITIZER_LIBS	:= -Wl,--no-as-needed -lasan -lubsan -Wl,--as-needed
DEBUG_FLAGS		:= -g3 -gdwarf-3 \
					-fsanitize=address,undefined \
					-fno-sanitize-recover=all

ifeq ($(COMPILER),clang)
	CLANG_RDIR	:= $(shell $(CPP) --print-resource-dir)

	# Use GCC's sanitizer runtimes (libasan/libubsan) instead of clang's compiler-rt.
	# https://stackoverflow.com/questions/77894856/possible-bug-in-gcc-sanitizers
	GCC_ASAN_SO	:= $(shell g++ -print-file-name=libasan.so)
	GCC_UBSAN_SO:= $(shell g++ -print-file-name=libubsan.so)
	GCC_SAN_DIR	:= $(shell dirname $(GCC_ASAN_SO))

	LINK_FLAGS	+= -Wl,--enable-new-dtags \
					-Wl,-z,now -Wl,-z,relro \
					-unwindlib=libgcc -rtlib=libgcc \
					-Wl,--no-as-needed -Wl,-l:libpthread.so.0 -Wl,--as-needed \
					-fno-sanitize-link-runtime \
					-L$(GCC_SAN_DIR) \
					-Wl,-rpath,$(GCC_SAN_DIR) # point rpath at GCC sanitizer directory.

	OPTIMIZE_FLAGS	+= -fstandalone-debug \
						-Wglobal-constructors \
						-Wexit-time-destructors \

else
	OPTIMIZE_FLAGS	+= -felide-constructors
endif

MANDATORY_FLAGS	:= -Wall -Wextra -Werror -std=c++98 \
					-Wshadow -Woverloaded-virtual -Wstrict-aliasing=2

INCLUDE_FLAGS	:= -I. -I./src -I$(INC_DIR) -I/usr/include

CXXFLAGS 		:= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) \
 						$(OPTIMIZE_FLAGS) $(INCLUDE_FLAGS)

SRC_DIR			= src
_SRCS			= main.cpp \
					PmergeMe.cpp

SRCS			:= $(_SRCS:%=$(SRC_DIR)/%)

OBJS			= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CXXFLAGS) $(SANITIZER_LIBS) $(OBJS) $(LINK_FLAGS) -o $@
		@echo "$(NAME) BUILD COMPLETE!"

$(BUILD_DIR)/%.o: %.cpp
		@if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
		$(CPP) $(CXXFLAGS) -c $^ -o $@

## yb
yb:
		@echo "Hey yublee!"

## clean
clean:
		@$(RM) -rf $(OBJS)

## fclean
fclean: clean
		@$(RM) -vf $(NAME)

re: fclean all

.PHONY: all clean fclean re yb
