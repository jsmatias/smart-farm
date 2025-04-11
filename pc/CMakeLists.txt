cmake_minimum_required(VERSION 3.16)
project(Dragonfly LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automoc for Qt6
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)  # If you're using Qt resources (.qrc files)

# Set source files
set(SOURCES
    src/main.cpp
    src/gui/MainWindow.cpp
    src/network/TcpClient.cpp
)
# Add executable
add_executable(Dragonfly ${SOURCES})

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)
# Link Qt libraries
target_link_libraries(Dragonfly PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)

# Include Qt headers and the src/gui directory for MainWindow.h
target_include_directories(Dragonfly PRIVATE
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Gui_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
    ${Qt6Network_INCLUDE_DIRS}
    src/gui
    src/network
)