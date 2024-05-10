include(common)

add_qt_executable(2_5_file_handling "2_5_file_handling.cpp")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
