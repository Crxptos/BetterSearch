cmake_minimum_required(VERSION 3.25)

# 1. This block helps CMake find Geode on GitHub Actions
if(NOT DEFINED Geode_DIR AND DEFINED env.GEODE_SDK)
    set(Geode_DIR "${env.GEODE_SDK}")
endif()

project(BetterSearch)

# 2. Find the SDK
find_package(Geode REQUIRED)

# 3. Create the mod
add_geode_mod(
    crxptos.bettersearch
    SOURCES BetterSearch.cpp
)
