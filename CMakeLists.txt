cmake_minimum_required(VERSION 3.21)

include(cmake/CPM.cmake)

CPMAddPackage("gh:geode-sdk/geode#v5.3.0")

geode_add_mod(BetterSearch
    src/BetterSearchMain.cpp
    src/BetterSearchLevels.cpp
    src/BetterSearchSong.cpp
    src/FuzzyText.cpp
)

geode_add_resources(${PROJECT_NAME} resources)
