cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find packages
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Enable automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


include(common)
# Define the executable
add_executable(my_app src/main.cpp)
add_subdirectory(src/Qt)
#
#add_qt_executable(hello_word "src/Qt/01_Introduction/hello_word.cpp")
#add_qt_executable(2_1_qt_core "src/Qt/02_Qt_core_basics/2_1_qt_core/2_1_qt_core.cpp")
#add_qt_executable(2_2_object_mapping "src/Qt/02_Qt_core_basics/2_2_object_mapping/2_2_object_mapping.cpp")
#add_qt_executable(2_3_timer_with_signal_and_slots "src/Qt/02_Qt_core_basics/2_3_signals_and_slots/2_3_timer_with_signal_and_slots.cpp")
#add_qt_executable(2_3_application_with_signals "src/Qt/02_Qt_core_basics/2_3_signals_and_slots/2_3_application_with_signals.cpp")
#add_qt_executable(2_4_signals_and_slots_with_events "src/Qt/02_Qt_core_basics/2_3_signals_and_slots/2_3_signals_and_slots_with_events.cpp")
#add_qt_executable(2_5_parent_child "src/Qt/02_Qt_core_basics/2_4_memory_management/2_4_parent_child.cpp")
#add_qt_executable(2_5_file_handling "src/Qt/02_Qt_core_basics/2_5_file_handling/2_5_file_handling.cpp")

# Use the Widgets module from Qt 5
target_link_libraries(my_app Qt5::Widgets Qt5::Core Qt5::Gui ${OpenCV_LIBS})
#target_link_libraries(hello_word Qt5::Widgets Qt5::Core Qt5::Gui)