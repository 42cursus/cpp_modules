# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:20:36 by abelov            #+#    #+#              #
#    Updated: 2025/07/26 21:19:47 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp04_ex02 CXX)
set(CMAKE_CXX_STANDARD 98)

set(TARGET_EXE_NAME "${PROJECT_NAME}_animals")

find_program(IWYU_PATH NAMES include-what-you-use iwyu)

if(IWYU_PATH)
	message(STATUS "Found IWYU: ${IWYU_PATH}")
	set(IWYU_TOOL_PATH "$ENV{HOME}/staging/include-what-you-use")
	set(IWYU_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")  # or AMateria.cpp etc.
	add_custom_target(cpp04_ex02_iwyu
			COMMAND ${PYTHON3_EXECUTABLE} ${IWYU_TOOL_PATH}/iwyu_tool.py
			-j 8 -p ${CMAKE_SOURCE_DIR}/build
			-- -Xiwyu --verbose=1 --regex
#			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
			COMMENT "Running include-what-you-use on cpp04/ex02"
	)
else()
	message(WARNING "IWYU not found. Include analysis will not run.")
endif()




add_executable(${TARGET_EXE_NAME}
		main.cpp
		Animal.cpp
		Cat.cpp
		Dog.cpp
		main.cpp
		Brain.cpp
)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_NAME "animals")

