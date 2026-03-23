cmake_minimum_required(VERSION 3.21)

project(BetterSearch)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ Load Geode SDK (THIS is the correct way)
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_BINARY_DIR}/geode)

# ✅ Explicit source files (no glob = more stable)
set(SOURCES
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# ✅ Build shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# ✅ Setup Geode mod
setup_geode_mod(${PROJECT_NAME})
