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
    boardmodel.cpp \
    game.cpp \
    player.cpp \
    referee.cpp

HEADERS += core.h\
        core_global.h \
    boardmodel.h \
    game.h \
    player.h \
    referee.h

win32 {
    target.path = $$PWD/../../../NoughtsAndCrosses-install
    INSTALLS += target
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
