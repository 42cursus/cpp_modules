# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 00:03:53 by abelov            #+#    #+#              #
#    Updated: 2025/02/26 00:03:54 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp02_ex02 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "${PROJECT_NAME}_fixed")

add_executable(${TARGET_EXE_NAME}
        main.cpp
        Fixed.cpp)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "fixed")
target_link_libraries(${TARGET_EXE_NAME} PRIVATE soft-fp64)
target_link_directories(${TARGET_EXE_NAME} PRIVATE "$ENV{HOME}/staging/ieeelib")
