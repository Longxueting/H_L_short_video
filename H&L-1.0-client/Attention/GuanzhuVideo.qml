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
        loops: 3
        MouseArea{
            anchors.fill: parent
            onClicked: {
                mediaPlayer.playbackState === MediaPlayer.PlayingState ? mediaPlayer.pause() : mediaPlayer.play()
            }
        }
    }
    Rectangle{
        Label{
            text: qsTr("<")
            anchors.centerIn: parent
            font.pointSize: 20
        }
        color: "white"
        height: 50
        width: 50
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        z:1
        MouseArea{
            anchors.fill:parent
            onClicked: {
                mediaPlayer.stop()
                loader.source = "Guanzhu.qml"
            }
        }
    }
    Component.onCompleted: {
        console.log(mediaPlayer.source)
        mediaPlayer.source = guanzhuSource
        mediaPlayer.play()
    }
}
