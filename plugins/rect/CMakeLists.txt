# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(RectProperty)

include_directories(BEFORE ../../lib )

set(Rect_SRCS rect.cpp)

QT4_WRAP_CPP(Rect_SRCS rect.h)

add_library(RectProperty SHARED ${Rect_SRCS})

add_dependencies(RectProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(RectProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS RectProperty  DESTINATION "${LIB_INSTALL_DIR}/propertyEditor")
