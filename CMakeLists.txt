cmake_minimum_required(VERSION 3.7)
project(OOP_lab2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
	src/main.cpp
	src/StatisticMultiset.h
	src/StatisticMultiset.cpp
	)


add_executable(OOP_lab2 ${SOURCE_FILES})