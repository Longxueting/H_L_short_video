import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: head_image
    width: 80
    height: 80
    Image {
        id: head_picture
        source: "file:///root/01.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
        anchors.fill: parent
    }
    Rectangle{
        id: mask
        width: parent.width
        height: parent.height
        radius: height/2
        color: "red"
        visible: false
    }
    OpacityMask{
        anchors.fill: head_picture
        source: head_picture
        maskSource: mask
    }
}
