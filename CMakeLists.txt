cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0072 NEW)

project(PixSocial VERSION 0.1.0)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(
	PixSocial
	src/main.cpp
	src/names.cpp
	src/character.cpp
	src/structs.cpp
)

target_link_libraries(
	PixSocial
)
