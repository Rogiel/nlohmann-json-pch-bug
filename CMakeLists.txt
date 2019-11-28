cmake_minimum_required(VERSION 3.16)
project(JsonPchBug LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(JsonPchBug main.cpp)
target_include_directories(JsonPchBug PUBLIC json/include)
target_precompile_headers(JsonPchBug PRIVATE <nlohmann/json.hpp>)

# HACK -- this "works" but is very hacky
#target_compile_definitions(JsonPchBug PRIVATE
#        and=&&
#        or=||
#        not=!
#)