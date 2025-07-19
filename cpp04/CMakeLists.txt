# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 22:43:40 by abelov            #+#    #+#              #
#    Updated: 2025/07/17 22:43:40 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

project(cpp04 CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_subdirectory(ex00)

