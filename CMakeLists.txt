cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

include(cmake/CPM.cmake)

CPMAddPackage("gh:geode-sdk/geode#v5.3.0")

geode_add_mod(${PROJECT_NAME}
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

geode_add_resources(${PROJECT_NAME} resources)
