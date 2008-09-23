# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(SizeProperty)

include_directories(BEFORE ../../lib )

set(Size_SRCS size.cpp)

QT4_WRAP_CPP(Size_SRCS size.h)

add_library(SizeProperty SHARED ${Size_SRCS})

add_dependencies(SizeProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(SizeProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS SizeProperty  DESTINATION "${LIB_INSTALL_DIR}/propertyEditor")
