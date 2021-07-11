cmake_minimum_required(VERSION 3.17)
project(TestChain)

set(CMAKE_CXX_STANDARD 20)

add_executable(TestChain main.cpp Block.h BlockChain.h sha256.cpp sha256.h Block.cpp BlockChain.cpp)