# (c) 2008 by BogDan Vatra < bogdan@licentia.eu >

cmake_minimum_required(VERSION 2.6)
project(propertyEditor-package)

# please choose between GPL or LGPL license
set (PROPERTYEDITOR_LICENSE "LGPL")

message("*** propertyEditor use ${PROPERTYEDITOR_LICENSE} license ***")


set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_VERBOSE_MAKEFILE ON)
#comment or remove the above line before release

set (PROPERTYEDITOR_VERSION_MAJOR 2)
set (PROPERTYEDITOR_VERSION_MINOR 1)
set (PROPERTYEDITOR_VERSION_RELEASE 3)
set (PROPERTYEDITOR_VERSION "${PROPERTYEDITOR_VERSION_MAJOR}.${PROPERTYEDITOR_VERSION_MINOR}.${PROPERTYEDITOR_VERSION_RELEASE}" )

add_definitions (-DPROPERTYEDITOR_VERSION=\"${PROPERTYEDITOR_VERSION}\")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" )
include(SetPaths.cmake)

IF(APPLE)
    IF(NOT PROPERTYEDITOR_HAS_BEEN_RUN_BEFORE)
        IF(EXISTS /Developer/SDKs/MacOSX10.5.sdk OR EXISTS /SDKs/MacOSX10.5.sdk)
            SET(CMAKE_OSX_ARCHITECTURES "ppc;i386;ppc64;x86_64" CACHE STRING "Build architectures for OSX" FORCE)
            SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden" CACHE STRING "Flags used by the compiler during all build types." FORCE)
        ELSE(EXISTS /Developer/SDKs/MacOSX10.5.sdk OR EXISTS /SDKs/MacOSX10.5.sdk)
            IF(EXISTS /Developer/SDKs/MacOSX10.4u.sdk OR EXISTS /SDKs/MacOSX10.4u.sdk)
                SET(CMAKE_OSX_ARCHITECTURES "ppc;i386" CACHE STRING "Build architectures for OSX" FORCE)
                SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden" CACHE STRING "Flags used by the compiler during all build types." FORCE)
           ENDIF(EXISTS /Developer/SDKs/MacOSX10.4u.sdk OR EXISTS /SDKs/MacOSX10.4u.sdk)
        ENDIF(EXISTS /Developer/SDKs/MacOSX10.5.sdk OR EXISTS /SDKs/MacOSX10.5.sdk)
        message("Build architectures for OSX:${CMAKE_OSX_ARCHITECTURES}")
    ENDIF(NOT PROPERTYEDITOR_HAS_BEEN_RUN_BEFORE)
ENDIF(APPLE)

find_package(Qt4 REQUIRED)

set( QT_USE_QTGUI   TRUE )
include( ${QT_USE_FILE} )
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${QT_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR})

add_definitions (-DLIB_INSTALL_DIR=\"${LIB_INSTALL_DIR}\")

add_subdirectory(lib)
add_subdirectory(plugins)
add_subdirectory(examples)

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

install(FILES cmake/modules/FindPropertyEditor.cmake DESTINATION ${CMAKE_ROOT}/Modules COMPONENT Devel)

# This needs to be run very last so other parts of the scripts can take
# advantage of this.
IF(NOT PROPERTYEDITOR_HAS_BEEN_RUN_BEFORE)
    SET(PROPERTYEDITOR_HAS_BEEN_RUN_BEFORE 1 CACHE INTERNAL "Flag to track whether this is the first time running CMake or if CMake has been configured before")
ENDIF(NOT PROPERTYEDITOR_HAS_BEEN_RUN_BEFORE)


