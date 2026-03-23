cmake_minimum_required(VERSION 3.21)
project(BetterSearch VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all cpp files
file(GLOB_RECURSE SOURCES
    /src
  BetterSearchMain.cpp
  BetterSearchSong.cpp
  BetterSearchLevels.cpp
  FuzzyText.cpp
    )

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# 🔥 THIS is the correct way (no find_package!)
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not set")
endif()

# Include Geode properly
add_subdirectory($ENV{GEODE_SDK} geode-sdk)

# Setup mod
setup_geode_mod(${PROJECT_NAME})
