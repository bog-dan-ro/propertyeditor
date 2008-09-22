# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(TimeProperty)

include_directories(BEFORE ../../lib )

set(Time_SRCS timeprop.cpp)

QT4_WRAP_CPP(Time_SRCS timeprop.h)

add_library(TimeProperty SHARED ${Time_SRCS})

add_dependencies(TimeProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(TimeProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS TimeProperty LIBRARY DESTINATION lib/propertyEditor)
