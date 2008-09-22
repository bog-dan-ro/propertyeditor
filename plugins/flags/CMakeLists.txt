# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(FlagsProperty)

include_directories(BEFORE ../../lib )

set(Flags_SRCS flags.cpp  flagslist.cpp)

QT4_WRAP_CPP(Flags_SRCS flags.h  flagslist.h)

QT4_WRAP_UI(Flags_SRCS flagsList.ui)


add_library(FlagsProperty SHARED ${Flags_SRCS})

add_dependencies(FlagsProperty PropertyEditor)

link_directories( "../../lib" )

target_link_libraries(FlagsProperty PropertyEditor ${QT_QTGUI_LIBRARY} 
        ${QT_QTCORE_LIBRARY} )

install(TARGETS FlagsProperty LIBRARY DESTINATION lib/propertyEditor)
