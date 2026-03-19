cmake_minimum_required(VERSION 3.25)

# This name can be anything, usually matches your mod name
project(BetterSearch)

# Find Geode SDK (Required for the GitHub Action)
find_package(Geode REQUIRED)

# Setup the mod using your ID
add_geode_mod(
    crxptos.bettersearch # Your Mod ID
    SOURCES main.cpp       # Change this if your file isn't named main.cpp
)
