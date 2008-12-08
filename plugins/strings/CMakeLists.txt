# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(StringsProperty)

include_directories(BEFORE "${CMAKE_SOURCE_DIR}/lib" )

set(Strings_SRCS strings.cpp)
QT4_WRAP_CPP(Strings_SRCS strings.h)

add_library(StringsProperty SHARED ${Strings_SRCS})
add_dependencies(StringsProperty PropertyEditor)
link_directories( "${CMAKE_BINARY_DIR}/lib" )
target_link_libraries(StringsProperty PropertyEditor ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY} )

install(TARGETS StringsProperty ${INSTALL_PLUGINS_DEFAULT_ARGS})
