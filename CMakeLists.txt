cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 17)

# ✅ This is REQUIRED for Geode
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# ✅ Your mod
geode_add_mod(BetterSearch
    src/BetterSearchMain.cpp
    src/BetterSearchLevels.cpp
    src/BetterSearchSong.cpp
    src/FuzzyText.cpp
)
