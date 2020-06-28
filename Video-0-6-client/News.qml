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
            model: 8
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
                            source: "file:///root/Video-0-2/Image/user1.png"
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
                            source: "file:///root/Video-0-2/Image/user1.png"
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
                            source: "file:///root/Video-0-2/Image/user1.png"
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
                            source: "file:///root/Video-0-2/Image/user1.png"
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
                    images.source:"file:///root/myVideo/vod/02.png"
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
