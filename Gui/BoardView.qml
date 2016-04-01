import QtQuick 2.5
import QtPositioning 5.3
import QtQuick.Controls 1.4

Item {
    id: rootItem

    Connections{
        target: myGame
        onStarted: lineAnim.start()
    }

    Canvas{
        id: canvas
        anchors.fill: parent
        anchors.margins: 50
        property point pnt1: Qt.point(width*1/3, 0)
        property point pnt2: Qt.point(width*1/3, height)
        property int lw: 0

        onHeightChanged: console.log("Height: " + height)

        onLwChanged: {
            console.log(lw);
            requestPaint();
        }

        onPaint: {
            var cntx = canvas.getContext('2d');
            cntx.clearRect(0, 0, width, height);
            cntx.strokeStyle = "black";
            cntx.lineWidth = 1
            cntx.beginPath();

            cntx.moveTo(pnt1.x, pnt1.y);
            cntx.lineTo(pnt1.x, pnt1.y+lw);

            // vertical lines
            cntx.moveTo(width*2/3, 0);
            cntx.lineTo(width*2/3, height);

            //horizontal lines
            cntx.moveTo(0, height*1/3);
            cntx.lineTo(width, height*1/3);
            cntx.moveTo(0, height*2/3);
            cntx.lineTo(width, height*2/3);

            cntx.stroke();
            cntx.restore();
        }

//        states: [
//            State {
//                name: "drawLine"
//                PropertyChanges {
//                    target: canvas
//                    lw: canvas.height
//                }
//            }
//        ]

//        transitions: [
//            Transition {
//                to: "drawLine"
//                PropertyAnimation {
//                    target: canvas
//                    property: "lw"
//                    to: 300//rootItem.height
//                    duration: 1000
//                    //running: true
//                }
//            }
//        ]

        NumberAnimation{
            id: lineAnim
            target: canvas
            property: "lw"
            //from: 0
            to: canvas.height
            duration: 1000
            //running: true
        }
    }

    GridView{
        id: grid
        anchors.fill: canvas
        cellHeight: height/3
        cellWidth: width/3

        model: boardModel
        delegate: BoardCellDelegate{
                width: grid.cellWidth
                height: grid.cellHeight
                cellSymbol: symbol
        }
    }
}
