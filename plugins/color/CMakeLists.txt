# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(ColorProperty)

include_directories(BEFORE ../../lib )

set(Color_SRCS changecolor.cpp  color.cpp)

QT4_WRAP_CPP(Color_SRCS changecolor.h  color.h)


add_library(ColorProperty SHARED ${Color_SRCS})

add_dependencies(ColorProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(ColorProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS ColorProperty LIBRARY DESTINATION lib/propertyEditor)
