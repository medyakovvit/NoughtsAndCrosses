import QtQuick 2.5
//import my.X_And_O.Player 1.0

Item {
    id: rootItem
    property var player

    Connections{
        target: rootItem.player
        onActiveChanged: highlighter.isActive = rootItem.player.active
    }

    onPlayerChanged: {
        if(player){
            highlighter.isActive = player.active;
            playerName.text = player.name;
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
        anchors.centerIn: highlighter
        width: 0.9*highlighter.width
        height: 0.9*highlighter.height

        Text{
            id: playerName
            anchors.centerIn: parent
        }
    }
}
