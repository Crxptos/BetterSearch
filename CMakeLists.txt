cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ FIX: fallback if env var missing
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

include($ENV{GEODE_SDK}/cmake/Geode.cmake)

geode_add_mod(BetterSearch
    src/BetterSearchMain.cpp
    src/BetterSearchLevels.cpp
    src/BetterSearchSong.cpp
    src/FuzzyText.cpp
)
