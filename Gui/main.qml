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

    PlayerInfo{
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 100
        height: 100
        player: myGame.firstPlayer
    }

    PlayerInfo{
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 100
        height: 100
        player: myGame.secondPlayer
    }

    Column{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20
        spacing: 5

        Button{
            text: qsTr("New game")

            onClicked: {
                if(myGame.active)
                    noteBook.foldPage();
                //myGame.reset();
                else
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
                myGame.clearBoard();
            }
        }

        Button{
            text: qsTr("Next player")

            onClicked: {
                myGame.nextPlayer();
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
