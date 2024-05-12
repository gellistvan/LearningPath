cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Find packages
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
#find_package(Qt5 COMPONENTS Widgets Core Gui Qml Quick REQUIRED)
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#set(ENV{RESOURCES_PATH} "${CMAKE_SOURCE_DIR}/resources/")
add_definitions(-DRESOURCES_PATH="${CMAKE_SOURCE_DIR}/resources/")


message(STATUS INFO ENV{RESOURCES_PATH})

option(BUILD_CPP_11 "Build C++11 examples" ON)
option(BUILD_QT "Build Qt examples" ON)
option(BUILD_OPEN_CV "Build OpenCV examples" ON)

# Define the executable
add_subdirectory(ModernC++)

if(BUILD_QT)
    add_subdirectory(Qt)
endif ()

if(BUILD_OPEN_CV)
    add_subdirectory(OpenCV)
endif ()

# Use the Widgets module from Qt 5
add_executable(my_app OpenCV/main.cpp)
target_link_libraries(my_app Qt5::Widgets Qt5::Core Qt5::Gui ${OpenCV_LIBS})
#target_link_libraries(hello_word Qt5::Widgets Qt5::Core Qt5::Gui)