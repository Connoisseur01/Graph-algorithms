cmake_minimum_required(VERSION 3.12)

project(Data-structures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")

set(TARGET_NAME
sdizo2)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(${TARGET_NAME} ${SOURCES})