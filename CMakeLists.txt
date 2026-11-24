cmake_minimum_required(VERSION 4.2)
project(dylemat_wieznia)

set(CMAKE_CXX_STANDARD 20)

add_executable(dylemat_wieznia GameMaster.cpp
        Generators.h
        NewDataTypes.cpp
        NewDataTypes.h
        Array2D.h)
