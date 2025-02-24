# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 23:43:23 by abelov            #+#    #+#              #
#    Updated: 2025/02/23 23:43:23 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp00_ex03 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "replace")

add_executable(${TARGET_EXE_NAME}
        main.cpp
        Replace.cpp)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${TARGET_EXE_NAME}")
