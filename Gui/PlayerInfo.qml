import QtQuick 2.5
import QtQuick.Layouts 1.1

Item {
    id: rootItem
    property var player

    Connections{
        target: rootItem.player
        onActiveChanged: highlighter.isActive = rootItem.player.active
        onWinsChanged: playerWins.text = wins
        onWon: winnerRect.state = "win"
    }

    Connections{
        target: myGame
        onReseted: winnerRect.state = ""
    }

    onPlayerChanged: {
        if(player){
            highlighter.isActive = player.active;
            playerName.text = player.name;
            playerWins.text = player.wins;
        }
    }

    Rectangle{
        id: highlighter
        anchors.fill: parent
        color: "#FFAA3B"

        opacity: 0.0
        property bool isActive: false

        onIsActiveChanged: {
            state = isActive ? "active" : "inactive"
        }

        states: [
            State {
                name: "active"
                PropertyChanges {
                    target: highlighter
                    opacity: 1.0
                }
            },

            State {
                name: "inactive"
                PropertyChanges {
                    target: highlighter
                    opacity: 0.0
                }
            }
        ]

        transitions: [
            Transition {
//                from: "fromState"
//                to: "toState"
                OpacityAnimator{
                    target: highlighter
                    duration: 500
                }
            }
        ]
    }

    Rectangle{
        id: rectInfo
        anchors.centerIn: highlighter
        width: 0.9*highlighter.width
        height: 0.9*highlighter.height

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 5

            RowLayout{
                Text{text: qsTr("Name:")}
                Text{
                    id: playerName
                    Layout.fillWidth: true
                }
            }

            RowLayout{
                Text{text: qsTr("Wins:")}
                Text{
                    id: playerWins
                    Layout.fillWidth: true
                }
            }
        }
    }

    Rectangle{
        id: winnerRect
        width: rectInfo.width
        height: rectInfo.height/3
        radius: 5
        color: "lightgreen"
        anchors.horizontalCenter: rectInfo.horizontalCenter
        y: highlighter.y+highlighter.height

        Text{
            anchors.centerIn: parent
            text: qsTr("Winner")
        }

        states: [
            State{
                name: ""
                PropertyChanges {
                    target: winnerRect
                    y: highlighter.y+highlighter.height
                }
            },
            State{
                name: "win"
                PropertyChanges {
                    target: winnerRect
                    y: highlighter.y+(highlighter.height-winnerRect.height)/2
                }
            }
        ]

        transitions: [
            Transition {
                SmoothedAnimation{
                    target: winnerRect
                    property: "y"
                    duration: 500
                }
            }
        ]
    }
}
