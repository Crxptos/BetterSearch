cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# Use Geode SDK
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

setup_geode_mod(
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
