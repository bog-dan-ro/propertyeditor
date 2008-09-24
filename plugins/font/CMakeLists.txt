# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(FontProperty)

include_directories(BEFORE ../../lib )

set(Font_SRCS changefont.cpp  font.cpp)

QT4_WRAP_CPP(Font_SRCS changefont.h  font.h)

add_library(FontProperty SHARED ${Font_SRCS})

add_dependencies(FontProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(FontProperty PropertyEditor ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY} )

install(TARGETS FontProperty  DESTINATION "${LIB_INSTALL_DIR}/propertyEditor")
