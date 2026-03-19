cmake_minimum_required(VERSION 3.25)

# This tells CMake where to look for the Geode-config.cmake file
# $ENV{GEODE_SDK} is set by the GitHub Action automatically
set(CMAKE_PREFIX_PATH $ENV{GEODE_SDK})

project(BetterSearch)

# Now it will check the CMAKE_PREFIX_PATH we just set
find_package(Geode REQUIRED)

add_geode_mod(
    crxptos.bettersearch
    SOURCES BetterSearch.cpp
)
