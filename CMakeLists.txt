cmake_minimum_required(VERSION 3.20)

project(interview_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(INTERVIEW_BUILD_TESTS "Build unit tests" ON)

if(MSVC)
    add_compile_options(/utf-8 /W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(interview_lab src/main.cpp)
target_include_directories(interview_lab PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(INTERVIEW_BUILD_TESTS)
    enable_testing()
endif()

