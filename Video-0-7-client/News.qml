import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./User"

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
            text: qsTr("消息")
            anchors.centerIn: parent
            font.pixelSize: 20
            color: "white"
        }
    }
    Rectangle{
        color: "black"
        width: parent.width
        height: parent.height
        ListView{
            anchors.fill:parent
            model: friendsModel
            header:Rectangle{
                color: "black"
                width: parent.width
                height: 120
                RowLayout{
                    anchors.top: parent.top
                    anchors.topMargin: 20
                    width: parent.width
                    Rectangle{
                        color: "black"
                        id: fans
                        anchors.left: parent.left
                        anchors.leftMargin: 0.05*parent.width
                        width:0.15*header.width
                        height: 100

                        Image {
                            id:fans_img
                            source: "qrc:/Image/fans.jpg"
                            width: parent.width
                            height: width
                        }
                        Text {
                            color: "white"
                            anchors.top: fans_img.bottom
                            anchors.horizontalCenter: fans_img.horizontalCenter
                            text: qsTr("粉丝")

                        }
                    }
                    Rectangle{
                        color: "black"
                        id: like
                        anchors.left: fans.right
                        anchors.leftMargin:  0.1*parent.width
                        width:0.15*header.width
                        height: 100
                        Image {
                            id:like_img
                            source: "qrc:/Image/like.jpg"
                            width: parent.width
                            height: width
                        }
                        Text {
                            color: "white"
                            anchors.top: like_img.bottom
                            anchors.horizontalCenter: like_img.horizontalCenter
                            text: qsTr("赞")
                        }
                    }
                    Rectangle{
                        color: "black"
                        id: about
                        anchors.left: like.right
                        anchors.leftMargin:  0.1*parent.width
                        width:0.15*header.width
                        height: 100
                        Image {
                            id:about_img
                            source: "qrc:/Image/about.jpg"
                            width: parent.width
                            height: width
                        }
                        Text {
                            color: "white"
                            anchors.top: about_img.bottom
                            anchors.horizontalCenter: about_img.horizontalCenter
                            text: qsTr("@我的")
                        }
                    }
                    Rectangle{
                        color: "black"
                        id: comment
                        anchors.left: about.right
                        anchors.leftMargin:  0.1*parent.width
                        width:0.15*header.width
                        height: 100
                        Image {
                            id:comment_img
                            source: "qrc:/Image/absert.jpg"
                            width: parent.width
                            height: width
                        }
                        Text {
                            color: "white"
                            anchors.top: comment_img.bottom
                            anchors.horizontalCenter: comment_img.horizontalCenter
                            text: qsTr("评论")
                        }
                    }
                }
                Rectangle{
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: 1
                    color: "#444444"
                }
            }
            ListModel{
                id: friendsModel
                ListElement{
                    userName: "冉东东"
                    lastMessage: "笑死我了 hhhhh"
                    lastTime: "17:50"
                    headImage: "qrc:/Image/avatar1.png"
                }
                ListElement{
                    userName: "小马同学"
                    lastMessage: "[转发]视频"
                    lastTime: "2:05"
                    headImage: "qrc:/Image/avatar2.png"
                }
                ListElement{
                    userName: "龚婷婷"
                    lastMessage: "啊啊啊啊啊 好帅呀"
                    lastTime: "昨天"
                    headImage: "qrc:/Image/avatar3.png"
                }
                ListElement{
                    userName: "小龙龙"
                    lastMessage: "嘿嘿嘿"
                    lastTime: "昨天"
                    headImage: "qrc:/Image/avatar4.png"
                }
                ListElement{
                    userName: "周小意"
                    lastMessage: "啊吧啊吧啊吧..."
                    lastTime: "三天前"
                    headImage: "qrc:/Image/avatar5.png"
                }

            }

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
                    images.source:headImage
                    width: 60
                    height: 60
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
                    id: message
                    color: "gray"
                    anchors.bottom: rec.bottom
                    anchors.bottomMargin: 15
                    anchors.left: head_image.right
                    anchors.leftMargin: 15

                    text:lastMessage
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
