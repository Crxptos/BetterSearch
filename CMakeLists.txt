cmake_minimum_required(VERSION 3.21)
project(BetterSearch VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Collect all source files
file(GLOB_RECURSE SOURCES
    /src
  BetterSearchMain.cpp
  BetterSearchSong.cpp
  BetterSearchLevels.cpp
  FuzzyText.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Ensure GEODE_SDK is set
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not set")
endif()

# Include Geode SDK manually (NO find_package!)
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# Setup mod
setup_geode_mod(${PROJECT_NAME})
