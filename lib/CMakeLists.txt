# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

project(propertyEditor)

set(PE_SRCS propertydelegate.cpp  propertyeditor.cpp  propertyinterface.cpp  propertymodel.cpp)
QT4_WRAP_CPP(PE_SRCS propertydelegate.h  propertyeditor.h  propertyinterface.h  propertymodel.h propertyvalidator.h)

if (WIN32)
  add_definitions(-DLIB_EXPORTS)
endif(WIN32)

add_library(PropertyEditor SHARED ${PE_SRCS})
set_target_properties(PropertyEditor PROPERTIES	VERSION ${PROPERTYEDITOR_VERSION}
                                        SOVERSION ${PROPERTYEDITOR_VERSION})
target_link_libraries(PropertyEditor ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} )

install(TARGETS PropertyEditor ${INSTALL_TARGETS_DEFAULT_ARGS} )
install(FILES propertyeditor.h propertyinterface.h propertyvalidator.h DESTINATION ${INCLUDE_INSTALL_DIR} COMPONENT Devel)
