cmake_minimum_required(VERSION 3.25)

# This line tells CMake where the SDK is located on GitHub's servers
if(NOT DEFINED Geode_DIR AND DEFINED ENV{GEODE_SDK})
    set(Geode_DIR "$ENV{GEODE_SDK}")
endif()

project(BetterSearch)

# Now find the package using the path set above
find_package(Geode REQUIRED)

add_geode_mod(
    crxptos.bettersearch
    SOURCES BetterSearch.cpp
)
