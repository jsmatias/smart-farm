cmake_minimum_required(VERSION 3.16)
project(Dragonfly LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automoc
set(CMAKE_AUTOMOC ON)

# Set source files
set(SOURCES
    src/main.cpp
    src/gui/MainWindow.cpp
)

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add executable
add_executable(Dragonfly ${SOURCES})

# Link Qt libraries
target_link_libraries(Dragonfly PRIVATE Qt6::Widgets)

# Include Qt headers and the src/gui directory for MainWindow.h
target_include_directories(Dragonfly PRIVATE ${Qt6Widgets_INCLUDE_DIRS} src/gui)

# Ensure all source files are included properly
target_sources(Dragonfly PRIVATE src/gui/MainWindow.cpp)
