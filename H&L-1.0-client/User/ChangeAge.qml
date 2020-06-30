import QtQuick 2.0
import QtQuick.Controls 2.12


Page {
    anchors.fill: parent
    width: 360
    height: 640
    property var str

    header: Rectangle{
        height: 50
        color: "black"
        Rectangle {
            id: tool
            height: 50
            width: 50
            color: "black"

            Label {
                anchors.centerIn: parent
                id: toolButton
                text: "<"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                color: "white"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: stackView.pop()
            }
        }
        Label{
            anchors.centerIn: parent
            text: "修改信息"
            color: "white"
        }
        Rectangle {
            id: tool2
            height: 50
            width: 50
            color: "black"
            anchors.right: parent.right
            Label {
                anchors.centerIn: parent
                id: toolButton2
                text: "保存"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                color: "white"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
//                    age = spinbox.value
                    ageText = str
                    stackView.pop()
                }
            }
        }

    }

    Rectangle{

        height: 70
        width: 340
        anchors.centerIn: parent

        Text {
            id: name1
            text: qsTr("修改年龄 : ")
            width: 100
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            anchors.horizontalCenter: spinbox.horizontalCenter
        }
        SpinBox {
            id: spinbox
            editable: true
            from: 0
            to: 100
            anchors.right: parent.right
            anchors.rightMargin: 20
            onValueChanged:  {
                console.log(spinbox.value)
                str = spinbox.value
            }
        }
    }

}
