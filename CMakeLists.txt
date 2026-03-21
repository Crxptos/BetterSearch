cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 17)

# 🚫 DO NOT USE find_package(Geode)

# ✅ Use CPM (Geode handles this automatically)
include(cmake/CPM.cmake)

CPMAddPackage(
    NAME geode
    GITHUB_REPOSITORY geode-sdk/geode
    VERSION 5.3.0
)

# Your mod
add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

target_link_libraries(${PROJECT_NAME} geode-sdk)

# Optional but good
target_compile_definitions(${PROJECT_NAME} PRIVATE GEODE_IS_MOD=1)
