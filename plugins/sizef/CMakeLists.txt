# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(SizefProperty)

include_directories(BEFORE ../../lib )

set(Sizef_SRCS sizef.cpp)

QT4_WRAP_CPP(Sizef_SRCS sizef.h)

add_library(SizefProperty SHARED ${Sizef_SRCS})

add_dependencies(SizefProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(SizefProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS SizefProperty  DESTINATION "${LIB_INSTALL_DIR}/propertyEditor")
