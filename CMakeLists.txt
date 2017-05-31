cmake_minimum_required(VERSION 3.7)
project(day2DayReinforcementC__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Rat.cpp Rat.h Trial.cpp Trial.h)
add_executable(day2DayReinforcementC__ ${SOURCE_FILES})