# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(RectfProperty)

include_directories(BEFORE ../../lib )

set(Rectf_SRCS rectf.cpp)

QT4_WRAP_CPP(Rectf_SRCS rectf.h)

add_library(RectfProperty SHARED ${Rectf_SRCS})

add_dependencies(RectfProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(RectfProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS RectfProperty LIBRARY DESTINATION lib/propertyEditor)
