import QtQuick 2.12
import QtQuick.Controls 2.5
import QtMultimedia 5.12

Page{
    id:videoplay
    height: 640
    width: 360
    property alias mediaplayer: mediaPlayer
    visible: true
    Video{
        anchors.fill: parent
        id:mediaPlayer
    }
    Button{
        text: qsTr("Cancel collection")
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        z:1
    }
    MouseArea{
        anchors.fill:parent
        onDoubleClicked: {
            mediaPlayer.stop()
            footBar.visible = true
            stackView.pop()
        }
    }
    Component.onCompleted: {
        console.log(mediaPlayer.source)
        mediaPlayer.source = videoSource
        mediaPlayer.play()
    }
}
