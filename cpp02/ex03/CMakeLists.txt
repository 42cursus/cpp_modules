# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 00:06:14 by abelov            #+#    #+#              #
#    Updated: 2025/02/26 00:06:14 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp00_ex03 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "bsp")

add_executable(${TARGET_EXE_NAME}
        main.cpp
        Fixed.cpp
        FixedSSE.cpp
        FixedX87.cpp
        Point.cpp
        bsp.cpp)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS} -std=c++98)
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lm -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${TARGET_EXE_NAME}")