cmake_minimum_required(VERSION 3.13)
project(HoneyBee)

set(CMAKE_CXX_STANDARD 11)

add_executable(HoneyBee main.cpp DataContainer.cpp DataContainer.h StatisticsBuffer.cpp StatisticsBuffer.h)