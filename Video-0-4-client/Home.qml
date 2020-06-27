import QtQuick 2.0
import QtQuick.Controls 2.12
import "./Home"

Page {
    width: 360
    height: 640
    property alias stopPlay: index.myVideo

    header:
        Rectangle{
        id:header
        color: "black"
        width: 360
        height: 40
            Text {
                id: text
                text: qsTr("首页")
                anchors.centerIn: parent
                font.pixelSize: 20
                color: "white"
            }
        }

    Index{
        id: index
    }

}
