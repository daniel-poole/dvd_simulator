cmake_minimum_required(VERSION 3.0)
project(dvd_simulator)
add_executable(dvd_simulator main.cpp)

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)
target_link_libraries(dvd_simulator sfml-system sfml-window sfml-graphics)