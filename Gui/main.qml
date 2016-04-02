import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

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

    RowLayout{
        anchors.fill: parent

        ColumnLayout{
            z: 1
            Layout.fillHeight: true
            Layout.minimumWidth: 100

            //Button new game and Player1 Info
            Item{
                Layout.minimumWidth: 100
                Layout.fillHeight: true
                Button{
                    anchors.centerIn: parent
                    text: qsTr("New game")

                    onClicked: {
                        if(myGame.firstRun)
                            myGame.start();
                        else
                            noteBook.foldPage();
                    }
                }
            }

            PlayerInfo{
                Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                Layout.minimumWidth: 100
                Layout.minimumHeight: 100
                player: myGame.firstPlayer
            }
        }

        // Notebook
        Item{
            z: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumHeight: 150

            NoteBook{
                id: noteBook
                anchors.centerIn: parent
                height: parent.height*0.90
                width: height*0.7
            }
        }

        //Player2 Info
        PlayerInfo{
            z: 1
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
            Layout.minimumWidth: 100
            Layout.minimumHeight: 100
            player: myGame.secondPlayer
        }
    }
}
