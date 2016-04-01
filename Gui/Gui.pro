TEMPLATE = app

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Library/Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Library/Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Library/Core/ -lCore

INCLUDEPATH += $$PWD/../Library/Core
DEPENDPATH += $$PWD/../Library/Core

DISTFILES += \
    NoteBook.qml \
    BoardView.qml \
    BoardCellDelegate.qml
