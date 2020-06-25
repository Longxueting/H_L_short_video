import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 360
    height: 640
    title: qsTr("Tabs")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Home{
        }
        Attention{
        }
        Shoot{
        }
        News{

        }
        User{

        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text1
                    anchors.centerIn: parent
                    text: qsTr("首页")
                    color: "white"
                }
            }
        }
        TabButton {
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text2
                    anchors.centerIn: parent
                    text: qsTr("关注")
                    color: "white"
                }
            }
        }
        TabButton {
            Rectangle{
                width: 72
                height: 40
                color: "transparent"

                Image {
                    id: shoot
                    width: 72
                    height: 40
                    anchors.centerIn: parent
                    source: "file:///run/media/root/study/H&L/UI/shoot.jpg"
                }
            }
        }
        TabButton {
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text3
                    anchors.centerIn: parent
                    text: qsTr("消息")
                    color: "white"
                }
            }
        }
        TabButton {
            Rectangle{
                width: 72
                height: 40
                color: "black"
                Text {
                    id: text4
                    anchors.centerIn: parent
                    text: qsTr("我")
                    color: "white"
                }
            }
        }
    }
}
