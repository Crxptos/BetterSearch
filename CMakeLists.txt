cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# Use Geode SDK
include(${GEODE_SDK}/cmake/Geode.cmake)

setup_geode_mod(
    NAME BetterSearch
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
