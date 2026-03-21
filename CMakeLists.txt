cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔥 Force using local Geode SDK (NO CPM fallback)
set(GEODE_DISABLE_CPM ON)
set(GEODE_USE_LOCAL_SDK ON)

# 🔥 Tell CMake where Geode is (CRITICAL)
# This makes find_package(Geode) actually work
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})
endif()

# 🔍 Find Geode
find_package(Geode REQUIRED)

# 📦 Your mod source files
add_library(${PROJECT_NAME} SHARED
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# 🔗 Link Geode
target_link_libraries(${PROJECT_NAME} Geode)

# (Optional but recommended)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    GEODE_IS_MOD=1
)
