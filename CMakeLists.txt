cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ THIS is the correct way for Geode mods
include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage(
    NAME Geode
    GITHUB_REPOSITORY geode-sdk/geode
    GIT_TAG v5.3.0
)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

target_link_libraries(${PROJECT_NAME} Geode)
