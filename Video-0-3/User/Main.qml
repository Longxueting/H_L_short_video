import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Page {
    id:player
    visible: true
    width: 360
    height: 400
    //title: qsTr("User")
    TabBar {
        id: tabBar
        anchors.bottom: swipeView.top
        width: parent.width
        currentIndex: swipeView.currentIndex
        z : 2

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
    SwipeView {
        id: swipeView
        anchors.fill: parent

        //anchors.fill: parent

        currentIndex: tabBar.currentIndex

        PageLike{
            padding: 1
        }

        MyVideo{

        }
    }
}

