cmake_minimum_required(VERSION 3.17)
project(BankBlockchain)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankBlockchain main.cpp Customer.cpp Customer.h Bank.h sha256.cpp sha256.h Block.cpp Block.h BlockChain.cpp BlockChain.h)