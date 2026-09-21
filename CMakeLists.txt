cmake_minimum_required(VERSION 3.10)
project(PokerEquityCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(poker_calc
    src/main.cpp
    src/card.cpp
    src/deck.cpp
    src/hand_evaluator.cpp
    src/simulator.cpp
)

target_include_directories(poker_calc PRIVATE include)