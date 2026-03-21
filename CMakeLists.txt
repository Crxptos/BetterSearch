cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔥 Use Geode (handled by CLI / action automatically)
find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

target_link_libraries(${PROJECT_NAME} Geode)
