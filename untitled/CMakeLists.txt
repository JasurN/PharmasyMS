cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
FIND_PACKAGE(PkgConfig REQUIRED)

INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)
add_executable(untitled ${SOURCE_FILES})

ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

add_definitions(${GTK_CFLAGS_OTHER})
target_link_libraries(untitled ${GTK_LIBRARIES})