cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# 🔥 THIS is the correct modern include
find_package(Geode REQUIRED)

# Create mod
geode_add_mod(${PROJECT_NAME}
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# Resources
geode_add_resources(${PROJECT_NAME} resources)
