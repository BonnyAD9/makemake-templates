cmake_minimum_required(VERSION 3.16)

project(${target} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${target})

file(GLOB ${target}_files CONFIGURE_DEPENDS "src/**/*.cpp" "src/*.cpp")
target_sources(${target} PRIVATE ${'${' target '_files}'})

# Uncomment to add link library
# target_link_libraries(${target} PRIVATE #[[ link library here ]])

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${'${CMAKE_CXX_FLAGS}'} -Wall -Wextra -Werror -fsanitize=address")
    target_link_libraries(${target} PRIVATE -fsanitize=address)
endif()
