#-------------------------------------------------
#
# Project created by QtCreator 2016-04-02T03:36:39
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_refereetest
CONFIG   += console testcase
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_refereetest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../../Core/ -lCore

INCLUDEPATH += $$PWD/../../Core
DEPENDPATH += $$PWD/../../Core
