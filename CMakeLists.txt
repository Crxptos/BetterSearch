cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ Use GEODE_SDK variable (from CMake, not ENV)
if (NOT DEFINED GEODE_SDK)
    message(FATAL_ERROR "GEODE_SDK not set")
endif()

# ✅ This is the MOST IMPORTANT LINE
include(${GEODE_SDK}/cmake/Geode.cmake)

# ✅ Let Geode handle everything
setup_geode_mod(
    NAME BetterSearch
    SOURCES
        src/BetterSearchMain.cpp
        src/BetterSearchSong.cpp
        src/BetterSearchLevels.cpp
        src/FuzzyText.cpp
)
