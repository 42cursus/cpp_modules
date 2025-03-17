# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 23:42:19 by abelov            #+#    #+#              #
#    Updated: 2025/02/19 23:42:23 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

project(cpp01 CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_subdirectory(ex00)
add_subdirectory(ex01)
add_subdirectory(ex02)
add_subdirectory(ex03)
add_subdirectory(ex04)
add_subdirectory(ex05)
add_subdirectory(ex06)
