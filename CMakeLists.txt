cmake_minimum_required(VERSION 3.10)
project(new_project)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(new_project src/main.cpp)

target_link_libraries(new_project OpenGL::GL GLUT::GLUT GLU)