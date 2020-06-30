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
        ListModel{
            id: talkModel
            ListElement{
                userName: "冉东东"
                lastMessage: "笑死我了 hhhhh"
                lastTime: "17:50"
                headImage: "qrc:/Image/avatar6.png"
            }
            ListElement{
                userName: "小马同学"
                lastMessage: "[转发]视频"
                lastTime: "2:05"
                headImage: "qrc:/Image/avatar7.png"
            }
            ListElement{
                userName: "龚婷婷"
                lastMessage: "啊啊啊啊啊 好帅呀"
                lastTime: "昨天"
                headImage: "qrc:/Image/avatar8.png"
            }
            ListElement{
                userName: "小龙龙"
                lastMessage: "嘿嘿嘿"
                lastTime: "昨天"
                headImage: "qrc:/Image/avatar9.png"
            }
            ListElement{
                userName: "周小意"
                lastMessage: "啊吧啊吧啊吧..."
                lastTime: "三天前"
                headImage: "qrc:/Image/avatar10.png"
            }

        }
        Rectangle{
            color: "black"
            width: parent.width
            height: parent.height
            ListView{
                anchors.fill:parent
                model: talkModel
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
                        images.source: headImage
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
                        text: userName
                        font.pixelSize: 20
                    }
                    Text {
                        id: nessage
                        color: "gray"
                        anchors.bottom: rec.bottom
                        anchors.bottomMargin: 15
                        anchors.left: head_image.right
                        anchors.leftMargin: 15

                        text: lastMessage
                        font.pixelSize: 15
                    }

                    Text {
                        id: time
                        color: "gray"
                        text: lastTime
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

