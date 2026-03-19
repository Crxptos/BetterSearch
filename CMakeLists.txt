cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ Correct SDK include (THIS is the fix)
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

geode_add_mod(BetterSearch
    src/BetterSearchMain.cpp
    src/BetterSearchLevels.cpp
    src/BetterSearchSong.cpp
    src/FuzzyText.cpp
)
