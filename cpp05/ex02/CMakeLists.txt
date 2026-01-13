# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:33:51 by abelov            #+#    #+#              #
#    Updated: 2025/07/25 21:33:51 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp05_ex02 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "${PROJECT_NAME}_form")

set(SRC_DIR src)

set(SOURCES
        main.cpp
        AForm.cpp
        Bureaucrat.cpp
        PresidentialPardonForm.cpp
        RobotomyRequestForm.cpp
        ShrubberyCreationForm.cpp
)

list(TRANSFORM SOURCES PREPEND "${SRC_DIR}/")

add_executable(${TARGET_EXE_NAME} ${SOURCES})

target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "form")
