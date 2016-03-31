import QtQuick 2.0

Item {
    GridView{
        id: grid
        anchors.fill: parent
        //anchors.centerIn: parent
        //width: 08*parent.width
        //height: width
        cellHeight: height/3
        cellWidth: width/3

        model: boardModel
        delegate: Component{
            Item{
                width: grid.cellWidth
                height: grid.cellHeight
                Rectangle{
                    anchors.fill: parent
                    anchors.margins: 10
                    border.color: "black"
                    border.width: 1

                    MouseArea{
                        anchors.fill: parent
                        onClicked: boardModel.setSymbol("x", index);
                    }
                }
            }
        }
    }
}
