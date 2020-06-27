import QtQuick 2.4
import QtQuick.Controls 2.12
import "./Attention"


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
                text: qsTr("关注")
                anchors.centerIn: parent
                font.pixelSize: 20
                color: "white"
            }
        }
    Follow{}
}
