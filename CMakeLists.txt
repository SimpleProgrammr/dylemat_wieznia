cmake_minimum_required(VERSION 4.2)
project(dylemat_wieznia)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_SOURCE_DIR}/config
        DESTINATION ${CMAKE_BINARY_DIR})

add_executable(dylemat_wieznia GameMaster.cpp
        misc/Generators.h
        misc/NewDataTypes.cpp
        misc/NewDataTypes.h
        misc/Array2D.h
        misc/Intercoms.cpp
        misc/Intercoms.h
        misc/SignalHandlers.cpp
        misc/SignalHandlers.h
)
