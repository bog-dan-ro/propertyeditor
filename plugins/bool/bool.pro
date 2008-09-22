TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti

INCLUDEPATH += $$[PROPERTY_EDITOR_INSTALL_HEADERS]

TARGET = BoolProperty

macx{
	QMAKE_LFLAGS +=  -F$$[PROPERTY_EDITOR_INSTALL_LIBS]
 	LIBS += -framework PropertyEditor
}else{
	LIBS += -L$$[PROPERTY_EDITOR_INSTALL_LIBS] -lPropertyEditor 
}

DESTDIR =.

HEADERS += bool.h

SOURCES += bool.cpp

RESOURCES += resource.qrc

target.path = $$[PROPERTY_EDITOR_INSTALL_PLUGINS]/propertyEditor

INSTALLS += target

