cmake_minimum_required(VERSION 3.21)
project(PA72)

set(CMAKE_CXX_STANDARD 11)

add_executable(PA72 main.cpp Map.cpp Map.h Player.cpp Player.h Monster.cpp Monster.h BattleSequence.cpp BattleSequence.h)
