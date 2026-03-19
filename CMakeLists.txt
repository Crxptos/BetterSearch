cmake_minimum_required(VERSION 3.21)
project(BetterSearch)

# ✅ This is the missing piece
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# ✅ Proper Geode mod setup
geode_add_mod(${PROJECT_NAME}
    src/BetterSearchMain.cpp
    src/BetterSearchSong.cpp
    src/BetterSearchLevels.cpp
    src/FuzzyText.cpp
)

# ✅ Resources
geode_add_resources(${PROJECT_NAME} resources)
