TEMPLATE = lib

CONFIG += exceptions \
dll \
plugin \
  rtti


TARGET = StringListProperty

DESTDIR = .

INCLUDEPATH += $$[PROPERTY_EDITOR_INSTALL_HEADERS]

macx{
	QMAKE_LFLAGS +=  -F$$[PROPERTY_EDITOR_INSTALL_LIBS]
 	LIBS += -framework PropertyEditor
}else{
	LIBS += -L$$[PROPERTY_EDITOR_INSTALL_LIBS] -lPropertyEditor 
}


target.path = $$[PROPERTY_EDITOR_INSTALL_PLUGINS]/propertyEditor

INSTALLS += target

SOURCES += stringlist.cpp \
stringlisteditor.cpp
HEADERS += stringlisteditor.h \
stringlist.h
FORMS += stringlisteditor.ui

RESOURCES += stringlist.qrc

