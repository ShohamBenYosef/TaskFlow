cmake_minimum_required(VERSION 3.10)

project(TaskFlow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(TaskFlow
    src/main.cpp
    src/Task.cpp
    src/BasicTask.cpp
    src/DeadlineTask.cpp
    src/TaskManager.cpp
)