import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id:player
    visible: true
    width: 360
    height: 640
    //title: qsTr("User")
    TabBar {
        id: tabBar
        anchors.bottom: swipeView.top
        width: parent.width
        currentIndex: swipeView.currentIndex
        background: Rectangle{
            color: "black"
        }


        TabButton {
//            text:
            height: 50
            Rectangle{
                height: 50
                width: parent.width
                anchors.fill: parent
                color: "black"
                Label{
                    anchors.centerIn: parent
                    text: qsTr("作品")
                    color: tabBar.currentIndex == 0 ? "white" : "grey"
                    font.pixelSize: 20
                }

            }
        }
        TabButton {
//            text: qsTr("喜欢")
            height: 50
            Rectangle{
                color: "black"
                height: 50
                width: parent.width

                Label{
                    anchors.centerIn: parent
                    text: qsTr("喜欢")
                    color: tabBar.currentIndex == 1 ? "white" : "grey"
                    font.pixelSize: 20
                }

            }
        }
    }
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        MyVideo{

        }
        PageLike{

        }
    }
}

