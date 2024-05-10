include(common)
add_qt_executable(3_1_box_layout "3_1_box_layout.cpp")
add_qt_executable(3_2_complex_example "3_2_complex_example.cpp")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
