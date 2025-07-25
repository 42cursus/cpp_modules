# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 19:28:23 by abelov            #+#    #+#              #
#    Updated: 2025/02/14 19:28:24 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_CXX_COMPILER g++)

project(cpp_modules CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

set(COMMON_LDFLAGS
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover=all
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow)
set(COMMON_CFLAGS
        -Wwrite-strings -Wnarrowing
		-frtti
        -O0
        -masm=att
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -fno-omit-frame-pointer
        -fdwarf2-cfi-asm
        -fcf-protection=none
        -g3 -gdwarf-3
        -fasynchronous-unwind-tables
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover=all
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow
)

add_subdirectory(cpp00)
add_subdirectory(cpp01)
add_subdirectory(cpp02)
add_subdirectory(cpp03)
add_subdirectory(cpp04)
add_subdirectory(cpp05)
add_subdirectory(cpp06)
add_subdirectory(cpp07)
