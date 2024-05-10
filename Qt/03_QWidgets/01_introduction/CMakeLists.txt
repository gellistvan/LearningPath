include(common)
add_qt_executable(3_1_button_with_clicks "3_1_button_with_clicks.cpp")
add_qt_executable(3_1_simple_form "3_1_simple_form.cpp")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
