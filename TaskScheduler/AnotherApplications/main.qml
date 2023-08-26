import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Task Management")
    Rectangle {
        id: task_bar
        color: "transparent"
        border.color: "red"
        border.width: 2
        width: parent.width
        height: 40
//        radius: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors {
            top: parent.top
        }

        Rectangle {
            id: file_taskbar
            width: 40
            height: parent.height
            color: "transparent"
            anchors {
                left: parent.left
                leftMargin: 10
            }

            Text {
                anchors.centerIn: parent
                font.pixelSize: 26
                text: "File"
            }

            MouseArea {
                anchors.fill: parent
                onReleased: {
                    console.log("Clicked on File")
                }
            }
        }
    }
}
