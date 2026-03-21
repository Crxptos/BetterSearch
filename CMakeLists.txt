cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔥 THIS is the correct way (DO NOT use include(Geode.cmake))
find_package(Geode REQUIRED)

# ✅ Your mod target
setup_geode_mod(
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
