# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 13:01:48 by abelov            #+#    #+#              #
#    Updated: 2025/02/14 13:01:49 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp00_ex01 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "hoarde")

add_executable(${TARGET_EXE_NAME}
        main.cpp
        Zombie.cpp
        zombieHorde.cpp)
target_compile_options(${TARGET_EXE_NAME}
        PRIVATE ${COMMON_CFLAGS}
        -fsanitize=address
)
target_link_options(${TARGET_EXE_NAME}
        PRIVATE ${COMMON_LDFLAGS}
        -g3
        -fsanitize=address
        -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${TARGET_EXE_NAME}")
