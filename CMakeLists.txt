cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ Correct include (works locally + CI)
if(DEFINED GEODE_SDK)
    include(${GEODE_SDK}/cmake/Geode.cmake)
elseif(DEFINED ENV{GEODE_SDK})
    include($ENV{GEODE_SDK}/cmake/Geode.cmake)
else()
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

setup_geode_mod(
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
