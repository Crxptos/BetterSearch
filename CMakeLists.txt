cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# ✅ THIS is the correct Geode include
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

setup_geode_mod(${PROJECT_NAME})
