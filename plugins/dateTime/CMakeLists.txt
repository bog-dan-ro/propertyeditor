# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(DateTimeProperty)

include_directories(BEFORE ../../lib )

set(DateTime_SRCS datetime.cpp)

QT4_WRAP_CPP(DateTime_SRCS datetime.h)

add_library(DateTimeProperty SHARED ${DateTime_SRCS})

add_dependencies(DateTimeProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(DateTimeProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS DateTimeProperty LIBRARY DESTINATION lib/propertyEditor)
