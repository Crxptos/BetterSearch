cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

include(cmake/CPM.cmake)

# Get Geode
CPMAddPackage("gh:geode-sdk/geode#v5.3.0")

# ✅ REQUIRED (you were missing this before sometimes)
include(${geode_SOURCE_DIR}/cmake/Geode.cmake)

# Your mod
geode_add_mod(BetterSearch
    src/BetterSearchMain.cpp
    src/BetterSearchLevels.cpp
    src/BetterSearchSong.cpp
    src/FuzzyText.cpp
)
