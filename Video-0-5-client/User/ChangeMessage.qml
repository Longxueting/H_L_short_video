import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    anchors.fill: parent
    width: 360
    height: 640
    //property alias toolButton: toolButton

    header: Rectangle{
        height: 50
        color: "grey"
        Rectangle {
            id: tool
            height: 50
            width: 50
            color: "grey"
            Label {
                anchors.centerIn: parent
                id: toolButton
                text: "<"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
            }
            MouseArea{
                anchors.fill: parent
                onClicked: stackView.pop()
            }
        }
        Label{
            anchors.centerIn: parent
            text: "xiugaixinxi"
        }
        Rectangle {
            id: tool2
            height: 50
            width: 50
            color: "grey"
            anchors.right: parent.right
            Label {
                anchors.centerIn: parent
                id: toolButton2
                text: "baocun"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    stackView.pop()
                }
            }
        }

    }

    Rectangle{
        width: parent.width - 20
        anchors.horizontalCenter: parent.horizontalCenter
        height: 320
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "blue"
        TextInput{
            id: textInput
            anchors.fill: parent
            anchors.margins: 5
            text: "qingjinxingxiugai"
            selectedTextColor: "#f01414"
            font.pointSize: 15
        }
    }
}
