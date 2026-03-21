cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ Correct way (works in CI)
if(DEFINED GEODE_SDK)
    include(${GEODE_SDK}/cmake/Geode.cmake)
else()
    include($ENV{GEODE_SDK}/cmake/Geode.cmake)
endif()

setup_geode_mod(
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
