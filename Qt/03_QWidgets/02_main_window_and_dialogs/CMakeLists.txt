include(common)
add_qt_executable(3_2_menubar_with_dialog "3_2_menubar_with_dialog.cpp")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
