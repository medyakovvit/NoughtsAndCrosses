import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Noughts and Crosses")

    Rectangle{
        anchors.fill: parent
        color: "darkgray"
    }

    Button{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20
        text: qsTr("New page")

        onClicked: {
            noteBook.foldPage();
        }
    }

    NoteBook{
        id: noteBook
        anchors.centerIn: parent
        height: parent.height*0.90
        width: height*0.7
    }
}
