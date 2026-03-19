cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# 🔥 REQUIRED: include Geode
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# Create mod
geode_add_mod(${PROJECT_NAME}
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# Add resources (images)
geode_add_resources(${PROJECT_NAME} resources)
