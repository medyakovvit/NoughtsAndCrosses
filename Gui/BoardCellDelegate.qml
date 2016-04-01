import QtQuick 2.0


Item{
    id: item
    property alias cellSymbol: canvas.symbol

    Rectangle{
        anchors.fill: parent
        anchors.margins: 10
        //border.color: "black"
        //border.width: 1

        Canvas{
            id: canvas
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height)
            height: width
            //anchors.fill: parent
            property string symbol

            property point line1Start: Qt.point(0,0)
            property point line1End: Qt.point(0,0)//(width,height)
            property point line2Start: Qt.point(width,0)
            property point line2End: Qt.point(width, 0)//(0,height)
            property real arcStartAngle: 0
            property real arcEndAngle: 0
            property int lineWidth: 2
            property color lineColor: "#0000ff"

            onLine1EndChanged: requestPaint()
            onLine2EndChanged: requestPaint()
            onArcEndAngleChanged: requestPaint()

            onSymbolChanged: {
                if(symbol === "")
                    state = "";
                else if(symbol === "x")
                    state = "drawX";
                else if(symbol === "o")
                    state = "drawO";
            }

            function drawSymbol(){
                if(symbol === "x")
                    drawX();

                else if(symbol === "o")
                    drawO();
            }

            function drawX(){
                if(line1Start === line1End)
                    return;

                var cntx = canvas.getContext('2d');
                cntx.strokeStyle = lineColor;
                cntx.lineWidth = lineWidth
                cntx.beginPath();
                cntx.moveTo(line1Start.x, line1Start.y);
                cntx.lineTo(line1End.x, line1End.y);
                cntx.stroke();
                cntx.restore();

                if(line2Start === line2End)
                    return;

                cntx.beginPath();
                cntx.moveTo(line2Start.x, line2Start.y);
                cntx.lineTo(line2End.x, line2End.y);
                cntx.stroke();
                cntx.restore();
            }

            function drawO(){
                if(arcStartAngle === arcEndAngle)
                    return;

                var cntx = canvas.getContext('2d');
                cntx.strokeStyle = '#0000ff';
                cntx.lineWidth = 2;
                cntx.beginPath();
                cntx.arc(width/2, height/2, width/2-lineWidth, arcStartAngle, arcEndAngle, false);
                cntx.stroke();
                cntx.restore();
            }

            states: [
                State {
                    name: ""
                    PropertyChanges {
                        target: canvas
                        line1End: Qt.point(0,0)
                    }
                    PropertyChanges {
                        target: canvas
                        line2End: Qt.point(width,0)
                    }
                },

                State {
                    name: "drawX"
                    PropertyChanges {
                        target: canvas
                        line1End: Qt.point(width,height)
                    }
                    PropertyChanges {
                        target: canvas
                        line2End: Qt.point(0,height)
                    }
                },

                State {
                    name: "drawO"
                    PropertyChanges {
                        target: canvas
                        arcEndAngle: 2*Math.PI
                    }
                }
            ]

            transitions: [
                Transition {
                    from: ""
                    to: "drawX"
                    SequentialAnimation{
                        PropertyAnimation{
                            target: canvas
                            property: "line1End"
                            duration: 500
                        }

                        PropertyAnimation{
                            target: canvas
                            property: "line2End"
                            duration: 500
                        }
                    }
                },

                Transition {
                    from: ""
                    to: "drawO"
                    PropertyAnimation{
                        target: canvas
                        property: "arcEndAngle"
                        duration: 500
                    }

                }
            ]

            onPaint: {
                var cntx = canvas.getContext('2d');
                cntx.clearRect(0, 0, width, height);
                drawSymbol();
            }
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                boardModel.setSymbol("x", index);
            }
        }
    }
}

