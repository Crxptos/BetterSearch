cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ Load Geode properly
find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# ✅ THIS gives you <Geode/...> headers
target_link_libraries(${PROJECT_NAME} Geode::Geode)
