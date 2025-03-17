# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 01:16:53 by abelov            #+#    #+#              #
#    Updated: 2025/03/17 01:16:54 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

project(cpp03 CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_subdirectory(ex00)
add_subdirectory(ex01)
add_subdirectory(ex02)
add_subdirectory(ex03)
