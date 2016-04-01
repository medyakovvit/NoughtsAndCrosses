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

    Column{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20
        spacing: 5

        Button{
            text: qsTr("New game")

            onClicked: {
                myGame.start();
            }
        }

        Button{
            text: qsTr("New page")

            onClicked: {
                noteBook.foldPage();
            }
        }

        Button{
            text: qsTr("Clear Model")

            onClicked: {
                boardModel.clearBoard();
            }
        }
    }

    NoteBook{
        id: noteBook
        anchors.centerIn: parent
        height: parent.height*0.90
        width: height*0.7
    }
}
