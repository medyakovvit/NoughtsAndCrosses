import QtQuick 2.5
import QtPositioning 5.3
import QtQuick.Controls 1.4

Item {
    id: rootItem
    visible: false

    Connections{
        target: myGame
        onStarted: {
            rootItem.visible = true;
            canvas.state = "drawGrid";
        }
        onReseted: {
            rootItem.visible = false;
            canvas.state = "";
        }
    }

    Canvas{
        id: canvas
        anchors.fill: parent
        anchors.margins: 50

        // Grid lines:
        // -Vertical lines
        property point line1Start: Qt.point(width*1/3,0)
        property point line1End: Qt.point(width*1/3,0)
        property point line2Start: Qt.point(width*2/3,0)
        property point line2End: Qt.point(width*2/3,0)

        // -Horizontal lines
        property point line3Start: Qt.point(0, height*1/3)
        property point line3End: Qt.point(0, height*1/3)
        property point line4Start: Qt.point(0, height*2/3)
        property point line4End: Qt.point(0, height*2/3)

        onLine1EndChanged: requestPaint()
        onLine2EndChanged: requestPaint()
        onLine3EndChanged: requestPaint()
        onLine4EndChanged: requestPaint()

        onPaint: {
            var cntx = canvas.getContext('2d');
            cntx.clearRect(0, 0, width, height);
            cntx.strokeStyle = "black";
            cntx.lineWidth = 1
            cntx.beginPath();

            // Draw grid's vertical lines
            if(line1Start !== line1End){
                cntx.moveTo(line1Start.x, line1Start.y);
                cntx.lineTo(line1End.x, line1End.y);
            }

            if(line2Start !== line2End){
                cntx.moveTo(line2Start.x, line2Start.y);
                cntx.lineTo(line2End.x, line2End.y);
            }

            // Draw grid's horizontal lines
            if(line3Start !== line3End){
                cntx.moveTo(line3Start.x, line3Start.y);
                cntx.lineTo(line3End.x, line3End.y);
            }

            if(line4Start !== line4End){
                cntx.moveTo(line4Start.x, line4Start.y);
                cntx.lineTo(line4End.x, line4End.y);
            }

            cntx.stroke();
            cntx.restore();
        }

        states: [
            State {
                name: ""
                PropertyChanges {
                    target: canvas
                    line1End: Qt.point(width*1/3,0)
                }
                PropertyChanges {
                    target: canvas
                    line2End: Qt.point(width*2/3,0)
                }
                PropertyChanges {
                    target: canvas
                    line3End: Qt.point(0, height*1/3)
                }
                PropertyChanges {
                    target: canvas
                    line4End: Qt.point(0, height*2/3)
                }
            },

            State {
                name: "drawGrid"
                PropertyChanges {
                    target: canvas
                    line1End: Qt.point(width*1/3, height)
                }
                PropertyChanges {
                    target: canvas
                    line2End: Qt.point(width*2/3, height)
                }
                PropertyChanges {
                    target: canvas
                    line3End: Qt.point(width, height*1/3)
                }
                PropertyChanges {
                    target: canvas
                    line4End: Qt.point(width, height*2/3)
                }
            }
        ]

        transitions: [
            Transition {
                from: ""
                to: "drawGrid"
                SequentialAnimation{
                    PropertyAnimation {
                        target: canvas
                        property: "line1End"
                        duration: 500
                    }

                    PropertyAnimation {
                        target: canvas
                        property: "line2End"
                        duration: 500
                    }

                    PropertyAnimation {
                        target: canvas
                        property: "line3End"
                        duration: 500
                    }

                    PropertyAnimation {
                        target: canvas
                        property: "line4End"
                        duration: 500
                    }
                }
            }
        ]
    }

    GridView{
        id: grid
        anchors.fill: canvas
        cellHeight: height/3
        cellWidth: width/3
        interactive: false

        model: myGame.board
        delegate: BoardCellDelegate{
            width: grid.cellWidth
            height: grid.cellHeight
            cellSymbol: symbol
        }
    }
}
