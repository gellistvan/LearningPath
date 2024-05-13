macro(add_qt_executable name sources)
    add_executable(${name} ${sources})
    target_link_libraries(${name} Qt5::Widgets Qt5::Core Qt5::Gui)
    set_target_properties(${name} PROPERTIES
            AUTOMOC ON
            AUTOUIC ON
            AUTORCC ON
            CMAKE_INCLUDE_CURRENT_DIR ON)

    message("=== Defined binary: ${name} ===")

endmacro()

macro(add_opencv_executable name sources)
    add_executable(${name} ${sources})
    target_link_libraries(${name} )
    message("=== Defined binary: ${name} ===")
endmacro()

macro(add_qt_cv_executable name sources)
    add_executable(${name} ${sources})
    target_link_libraries(${name} Qt5::Widgets Qt5::Core Qt5::Gui ${OpenCV_LIBS})
    set_target_properties(${name} PROPERTIES
            AUTOMOC ON
            AUTOUIC ON
            AUTORCC ON
            CMAKE_INCLUDE_CURRENT_DIR ON)

    message("=== Defined binary: ${name} ===")

endmacro()