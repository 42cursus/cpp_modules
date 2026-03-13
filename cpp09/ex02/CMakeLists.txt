# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:46:27 by abelov            #+#    #+#              #
#    Updated: 2025/07/25 21:46:27 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(cpp09_ex02 CXX)
set(CMAKE_CXX_STANDARD 98)

set(OUTPUT_NAME "PmergeMe")
set(TARGET_EXE_NAME "${PROJECT_NAME}_${OUTPUT_NAME}")

set(SRC_DIR src)

set(SOURCES
        main.cpp
        PmergeMe.cpp
)

list(TRANSFORM SOURCES PREPEND "${SRC_DIR}/")

add_executable(${TARGET_EXE_NAME} ${SOURCES})

set(SANITIZER_LINK_OPTIONS
        -Wl,--no-as-needed
        -lasan
        -lubsan
        -Wl,--as-needed
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    find_program(GXX_EXECUTABLE g++)
    if (GXX_EXECUTABLE)
        execute_process(
                COMMAND "${GXX_EXECUTABLE}" -print-file-name=libasan.so
                OUTPUT_VARIABLE GCC_ASAN_SO
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        if (GCC_ASAN_SO AND NOT GCC_ASAN_SO STREQUAL "libasan.so")
            get_filename_component(GCC_SAN_DIR "${GCC_ASAN_SO}" DIRECTORY)
            list(APPEND SANITIZER_LINK_OPTIONS
                    -Wl,--enable-new-dtags
                    -Wl,-z,now
                    -Wl,-z,relro
                    -unwindlib=libgcc
                    -rtlib=libgcc
                    -Wl,--no-as-needed
                    -Wl,-l:libpthread.so.0
                    -Wl,--as-needed
                    -fno-sanitize-link-runtime
                    -L${GCC_SAN_DIR}
                    -Wl,-rpath,${GCC_SAN_DIR}
            )
        endif ()
    endif ()
endif ()

target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS} ${SANITIZER_LINK_OPTIONS} -lstdc++)
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${OUTPUT_NAME}")
