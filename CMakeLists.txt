cmake_minimum_required(VERSION 3.26)
project(calculator)

set(CMAKE_CXX_STANDARD 17)



add_executable(calculator main.cpp
        components/Parser.cpp
        components/Parser.h
        components/Calculator.cpp
        components/Calculator.h
        components/Evalue.cpp
        components/Evalue.h
        components/LoaderLibrary.cpp
        components/LoaderLibrary.h
        components/DownloadLibrary.cpp
        components/DownloadLibrary.h
)