# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:27:20 by abelov            #+#    #+#              #
#    Updated: 2025/07/25 21:27:21 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp04_ex01 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "${PROJECT_NAME}_form")

add_executable(${TARGET_EXE_NAME}
        src/main.cpp
        src/Bureaucrat.cpp
        src/Form.cpp
)

target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "form")

