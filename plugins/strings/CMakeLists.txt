# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(StringsProperty)

include_directories(BEFORE ../../lib )

set(Strings_SRCS strings.cpp)

QT4_WRAP_CPP(Strings_SRCS strings.h)

add_library(StringsProperty SHARED ${Strings_SRCS})

add_dependencies(StringsProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(StringsProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS StringsProperty LIBRARY DESTINATION lib/propertyEditor)
