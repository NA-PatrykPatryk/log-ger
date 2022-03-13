cmake_minimum_required(VERSION 3.0)
project(LOGGER CXX)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(logger src/logger.cpp)
