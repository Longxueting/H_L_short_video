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
        currentIndex: tabBar.currentIndex

        PageLike{

        }

        MyVideo{

        }
    }
}

