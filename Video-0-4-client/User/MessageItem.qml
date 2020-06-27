import QtQuick 2.0



Rectangle{
    width: 360
    height: 50
    property alias itemClick: itemClick
    property alias textSet: name2
    Text {
        id: name1
        text: qsTr("text1")
        anchors.left: parent.left
        anchors.leftMargin: 20
    }
    Text {
        id: name2
        text: qsTr("text2")
        anchors.right: parent.right
        anchors.rightMargin: 10
    }
    MouseArea{
        anchors.fill: parent
        id: itemClick
    }
}


