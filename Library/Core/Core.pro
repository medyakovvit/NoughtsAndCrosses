#-------------------------------------------------
#
# Project created by QtCreator 2016-03-31T00:14:25
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += core.cpp \
    boardmodel.cpp

HEADERS += core.h\
        core_global.h \
    boardmodel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
