# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 00:06:42 by abelov            #+#    #+#              #
#    Updated: 2025/02/20 00:06:43 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp01_ex00 CXX C ASM)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "zombie")

add_executable(${TARGET_EXE_NAME}
        main.cpp
        Zombie.cpp
        newZombie.cpp
        randomChump.cpp)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${TARGET_EXE_NAME}")
