import QtQuick 2.0
import QtQuick.Controls 2.12


Page {
    width: 360
    height: 640

    header:
        Rectangle{
        id:header
        color: "black"
        width: 360
        height: 40
            Text {
                id: text
                text: qsTr("拍摄")
                anchors.centerIn: parent
                font.pixelSize: 20
                color: "white"
            }
        }
    Rectangle{
        id:content
        width: 360
        height: 560
        color: "black"
    }
}
