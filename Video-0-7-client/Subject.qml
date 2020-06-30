import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    visible: true
    width: 360
    height: 640
//    title: qsTr("Tabs")
    property alias footBar: tabBar

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Home{
            id: myhome
        }
        Attention{
            id: myfollow
        }
        Shoot{

        }
        News{

        }
        User{

        }
        onCurrentIndexChanged: {
            if(currentIndex == 0){
                myhome.stopPlay.play()
                myfollow.loader.source = ""
            }else if(currentIndex == 1){
                myhome.stopPlay.pause()
                myfollow.loader.source = "Follow.qml"
            }else{
                myhome.stopPlay.pause()
                myfollow.loader.source = ""
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            id: homeitem
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text1
                    anchors.centerIn: parent
                    text: qsTr("首页")
                    color: "white"
                    font.pixelSize: 15
                }
            }
        }
        TabButton {
            id: guanzhu
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text2
                    anchors.centerIn: parent
                    text: qsTr("关注")
                    color: "white"
                    font.pixelSize: 15
                }
            }

        }
        TabButton {
            id: myshoot
            Rectangle{
                width: 72
                height: 40
                color: "transparent"

                Image {
                    id: shoot
                    width: 73
                    height: 40
                    anchors.centerIn: parent
                    source: "qrc:/Image/video.jpg"
                }
            }
        }
        TabButton {
            id:message
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text3
                    anchors.centerIn: parent
                    text: qsTr("消息")
                    color: "white"
                    font.pixelSize: 15
                }
            }
        }
        TabButton {
            id: me
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text4
                    anchors.centerIn: parent
                    text: qsTr("我")
                    color: "white"
                    font.pixelSize: 15
                }
            }
        }
    }
}
