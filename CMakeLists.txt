cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔥 HARD OVERRIDE (this is the missing piece)
set(GEODE_DISABLE_CPM ON)
set(GEODE_USE_LOCAL_SDK ON)

# 🔍 Use installed SDK only
find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

target_link_libraries(${PROJECT_NAME} Geode)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    GEODE_IS_MOD=1
)
