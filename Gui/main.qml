import QtQuick 2.5
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

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
            foldedPage.state = "fold";
        }
    }

    Rectangle{
        id: pageRect
        anchors.centerIn: parent
        height: parent.height*0.90
        width: height*0.7
        border.color: "black"
        border.width: 1

        Rectangle{
            id: foldedPage
            width: parent.width
            anchors.left: parent.left
            anchors.right: parent.right
            y: parent.height
            height: 0
            border.color: pageRect.border.color
            border.width: pageRect.border.width

            property real gradientOpacity: 1.0

            function reset(){
                state = "";
            }

            LinearGradient{
                id: gradient
                anchors.fill: parent
                anchors.margins: 1
                opacity: parent.gradientOpacity

                start: Qt.point(0, foldedPage.height)
                end: Qt.point(0, foldedPage.height-pageRect.height)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#888888" }
                    GradientStop { position: 0.05; color: "white" }
                }
            }

            states: [
                State{
                    name: ""
                    PropertyChanges {
                        target: foldedPage
                        height: 0
                    }
                    PropertyChanges {
                        target: foldedPage
                        y: pageRect.height
                    }
                    PropertyChanges {
                        target: foldedPage
                        gradientOpacity: 1.0
                    }
                },

                State {
                    name: "fold"
                    PropertyChanges {
                        target: foldedPage
                        height: pageRect.height
                    }
                    PropertyChanges {
                        target: foldedPage
                        y: -(pageRect.height+pageRect.y)
                    }
                }
            ]

            transitions: Transition{
                from: ""
                to: "fold"
                onRunningChanged: {
                    if(!running)
                        foldedPage.reset();
                }

                ParallelAnimation{
                    id: foldAnimation
                    property int foldDuration: 2000
                    readonly property real foldVelocity: pageRect.height/foldDuration

                    PropertyAnimation{
                        target: foldedPage
                        property: "y"
                        from: pageRect.height
                        to: -pageRect.height
                        duration: foldAnimation.foldDuration
                    }

                    SequentialAnimation{
                        PropertyAnimation{
                            target: foldedPage
                            property: "height"
                            from: 0
                            to: 0.8*pageRect.height
                            duration: 0.8*pageRect.height/foldAnimation.foldVelocity
                        }

                        ParallelAnimation{
                            PropertyAnimation{
                                target: foldedPage
                                property: "height"
                                from: 0.8*pageRect.height
                                to: pageRect.height
                                duration: 0.2*pageRect.height/foldAnimation.foldVelocity
                            }

                            PropertyAnimation{
                                target: foldedPage
                                property: "gradientOpacity"
                                to: 0.0
                                duration: 0.2*pageRect.height/foldAnimation.foldVelocity
                            }
                        }

                        PropertyAnimation{
                            target: foldedPage
                            property: "y"
                            from: -pageRect.height
                            to: -(pageRect.height+pageRect.y)
                            duration: pageRect.y/foldAnimation.foldVelocity
                        }
                    }
                }
            }
        }
    }
}
