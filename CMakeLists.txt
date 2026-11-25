cmake_minimum_required(VERSION 4.2)
project(dylemat_wieznia)

set(CMAKE_CXX_STANDARD 20)

add_executable(dylemat_wieznia GameMaster.cpp
        misc/Generators.h
        misc/NewDataTypes.cpp
        misc/NewDataTypes.h
        misc/Array2D.h
        misc/Intercoms.cpp
        misc/Intercoms.h
)
