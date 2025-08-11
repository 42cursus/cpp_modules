# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:20:36 by abelov            #+#    #+#              #
#    Updated: 2025/07/25 21:20:37 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp04_ex03 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "${PROJECT_NAME}_materia")

add_executable(${TARGET_EXE_NAME}
		main.cpp
		AMateria.cpp
		Character.cpp
		Cure.cpp
		Ice.cpp
		ICharacter.cpp
		IMateriaSource.cpp
		MateriaSource.cpp
)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_NAME "materia")
