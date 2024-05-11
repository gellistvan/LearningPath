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

# Enable automatic MOC, UIC, and RCC processing
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


include(common)
# Define the executable
add_executable(my_app OpenCV/main.cpp)
add_subdirectory(ModernC++)
add_subdirectory(Qt)

# Use the Widgets module from Qt 5
target_link_libraries(my_app Qt5::Widgets Qt5::Core Qt5::Gui ${OpenCV_LIBS})
#target_link_libraries(hello_word Qt5::Widgets Qt5::Core Qt5::Gui)