cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

# 👇 THIS is the correct link for the action
target_link_libraries(${PROJECT_NAME} geode)
