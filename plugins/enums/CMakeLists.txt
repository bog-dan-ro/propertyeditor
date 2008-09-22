# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(EnumsProperty)

include_directories(BEFORE ../../lib )

set(Enums_SRCS enums.cpp)

QT4_WRAP_CPP(Enums_SRCS enums.h)

add_library(EnumsProperty SHARED ${Enums_SRCS})

add_dependencies(EnumsProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(EnumsProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS EnumsProperty LIBRARY DESTINATION lib/propertyEditor)
