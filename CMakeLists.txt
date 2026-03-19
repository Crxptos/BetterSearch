cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ THIS is the correct include (environment variable)
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

geode_add_mod(${PROJECT_NAME}
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

geode_add_resources(${PROJECT_NAME} resources)
