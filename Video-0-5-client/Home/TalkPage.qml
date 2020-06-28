import QtQuick 2.0
import QtQuick.Controls 2.12
import "../User"

Rectangle {
    id: talkPage
    color: Qt.rgba(255/255,255/255,255/255,0.3)
    width: 360
    height: 640
    radius: 10
    visible: false
    Page{
        width: 360
        height: 500
        anchors.bottom: parent.bottom
        header:Rectangle{
            id:header
            color: "black"
            width: 360
            height: 40
            Text {
                id: text
                text: qsTr("178pinlun")
                anchors.centerIn: parent
                font.pixelSize: 20
                color: "white"
            }
            Rectangle {
                id: tool
                height: 40
                width: 40
                radius: 20
                anchors.right: parent.right
                color: Qt.rgba(255/255,255/255,255/255,0.1)
                Label {
                    anchors.centerIn: parent
                    id: toolButton
                    text: "*"
                    font.pixelSize: Qt.application.font.pixelSize * 1.6
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: talkPage.visible = false
                }
            }
        }
        Rectangle{
            color: "black"
            width: parent.width
            height: parent.height
            ListView{
                anchors.fill:parent
                model: 8
                clip: true

                delegate: Rectangle{
                    id:rec
                    height: 80
                    width: header.width
                    color: "black"
                    HeadImage{
                        id: head_image
                        anchors.top: rec.top
                        anchors.topMargin: 10
                        anchors.left: rec.left
                        anchors.leftMargin: header.width*0.05
                        images.source:"file:///root/02.png"
                        width: 50
                        height: 50
                    }
                    Text {
                        id: username
                        color: "white"
                        anchors.top: rec.top
                        anchors.left: head_image.right
                        anchors.topMargin: 15
                        anchors.leftMargin: 15
                        text: qsTr("用户1")
                        font.pixelSize: 20
                    }
                    Text {
                        id: nessage
                        color: "gray"
                        anchors.bottom: rec.bottom
                        anchors.bottomMargin: 15
                        anchors.left: head_image.right
                        anchors.leftMargin: 15

                        text: qsTr("你在干嘛呀")
                        font.pixelSize: 15
                    }

                    Text {
                        id: time
                        color: "gray"
                        text: qsTr("00:00")
                        anchors.right:  rec.right
                        anchors.rightMargin: 15
                        anchors.top: rec.top
                        anchors.topMargin: 10
                        font.pixelSize: 10
                    }
                }
            }
        }

    }
    MouseArea{
        height: 100
        width: parent.width
        x : 0
        y : 0
        onClicked:{
            talkPage.visible = false
        }
    }
}

