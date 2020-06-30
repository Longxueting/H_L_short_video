import QtQuick 2.0



Rectangle{
    width: 360
    height: 50
    property alias itemClick: itemClick
    property alias textSetName2: name2.text
    property alias textSetName1: name1.text
    color: "black"
    Text {
        id: name1
        text: qsTr("text1")
        anchors.left: parent.left
        anchors.leftMargin: 20
        color: "white"
    }
    Text {
        id: name2
        text: qsTr("text2")
        width: 150
        anchors.right: parent.right
        anchors.rightMargin: 10
        horizontalAlignment: Text.AlignRight
        elide: Text.ElideRight
        color: "white"
    }
    MouseArea{
        anchors.fill: parent
        id: itemClick
    }
}


