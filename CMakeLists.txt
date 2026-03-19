cmake_minimum_required(VERSION 3.25)

# This line forces CMake to look in the GitHub Action's SDK folder
set(CMAKE_PREFIX_PATH $ENV{GEODE_SDK})

project(BetterSearch)

# This should now find the package successfully
find_package(Geode REQUIRED)

add_geode_mod(
    crxptos.bettersearch
    SOURCES BetterSearch.cpp
)
