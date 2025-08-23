cmake_minimum_required(VERSION 3.21)

project(${target} VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${target})

file(GLOB ${target}_files CONFIGURE_DEPENDS "src/**/*.c" "src/*.c")
target_sources(${target} PRIVATE ${'${' target '_files}'})

# Uncomment to add link library (math here)
# target_link_libraries(${target} PRIVATE -lm)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${'${CMAKE_C_FLAGS}'} -Wall -Wextra -Werror -fsanitize=address")
    target_link_libraries(${target} PRIVATE -fsanitize=address)
endif()
