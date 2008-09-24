# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(BrushProperty)

include_directories(BEFORE ../../lib )

set(Brush_SRCS brush.cpp)

QT4_WRAP_CPP(Brush_SRCS brush.h)

add_library(BrushProperty SHARED ${Brush_SRCS})

add_dependencies(BrushProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(BrushProperty PropertyEditor ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY} )

install(TARGETS BrushProperty DESTINATION "${PLUGIN_INSTALL_DIR}" RUNTIME)
