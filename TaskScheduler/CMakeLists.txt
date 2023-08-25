cmake_minimum_required(VERSION 3.10)

project(TaskManagement)

include_directories(inc)

set(SRCFILE src/TaskManagement.cpp
            src/UserAuthentication.cpp
    )

add_executable(program main.cpp ${SRCFILE})

add_compile_options(-Wall)
