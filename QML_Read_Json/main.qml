import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

ApplicationWindow {
    id: mainPage
    visible: true
    width: 400
    height: 680
    title: qsTr("My video player")

    ListModel{
        id: videoModel1
        ListElement{
            imageSource: "file:///root/05.png"
            videoSource: "file:///root/myVideo/receive5.flv"
        }
        ListElement{
            imageSource: "file:///root/01.png"
            videoSource: "file:///root/myVideo/receive1.flv"
        }
        ListElement{
            imageSource: "file:///root/02.png"
            videoSource: "file:///root/myVideo/receive2.flv"
        }
        ListElement{
            imageSource: "file:///root/03.png"
            videoSource: "file:///root/myVideo/receive3.flv"
        }
        ListElement{
            imageSource: "file:///root/04.png"
            videoSource: "file:///root/myVideo/receive4.flv"
        }
        ListElement{
            imageSource: "file:///root/05.png"
            videoSource: "file:///root/myVideo/receive5.flv"
        }
        ListElement{
            imageSource: "file:///root/01.png"
            videoSource: "file:///root/myVideo/receive1.flv"
        }
    }

    Component{
        id: delegate
        Rectangle{
            width: mainPage.width
            height: mainPage.height
            property alias video: video
            property alias like: is_like
            property alias notLike: not_like
            property bool isLike: hlIsLike

            Rectangle{  //进度条
                id: progressBar
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                height: 1
                //position保存当前播放的位置
                width: video.duration > 0?parent.width*video.position/video.duration : 0
                color: "white"
                z:2

            }

            Image {
                id: image
                width: mainPage.width
                height: mainPage.height
                source: hlVideoImage
            }
            Video{
                id: video
                anchors.fill: parent
                fillMode: VideoOutput.Stretch
                visible: true
                source: hlVideoSource
                loops: MediaPlayer.Infinite
                autoPlay: false
            }
            Image {
                id: not_like
                source: "/Image/icon_home_like_before.png"
                width: 60
                height: 60
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 330
                anchors.rightMargin: 15
                MouseArea{
                    anchors.fill: not_like
                    onClicked: {
                        like.visible = true
                        notLike.visible = false
                        $Model.setLikeNum(index,1)
                    }
                }
            }
            Image {
                id: is_like
                source: "/Image/icon_home_like_after.png"
                width: 60
                height: 60
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 330
                anchors.rightMargin: 15
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        like.visible = false
                        notLike.visible = true
                        $Model.setLikeNum(index,-1)
                    }
                }
            }
            Text{       //点赞人数
                id:hearttext
                text: hlLikeNum
                anchors.top: not_like.bottom
                anchors.left: not_like.left
                anchors.leftMargin: (not_like.width-hearttext.text.length)/3
                color: "white"
                z:1
            }

            Image {
                id: toTalk
                source: "/Image/pinglun (3).png"
                width: 50
                height: 50
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 420
                anchors.rightMargin: 17
            }
            Image {
                id: relay
                source: "/Image/zhuanfa.png"
                width: 50
                height: 50
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 510
                anchors.rightMargin: 17
            }
        }
    }

    ListView{
        id:listview
        anchors.fill: parent
        model: $Model
        orientation: verticalLayoutDirection
        highlightRangeMode:ListView.StrictlyEnforceRange
        snapMode: ListView.SnapOneItem
        delegate: delegate
        onMovementEnded: {
            console.log("end:",currentIndex)
            if(currentIndex == 6){
                listview.contentY = mainPage.height
            }
            if(currentIndex == 0){
                listview.contentY = 5*mainPage.height
            }
            currentItem.video.play()


            currentItem.video.seek(currentItem.video.position - 50000)
        }

        onCurrentItemChanged: {
            if(currentItem.isLike === false){
                currentItem.like.visible = false
            }
        }

        Component.onCompleted: {
            currentItem.video.play()
            currentItem.like.visible = false
        }

        onMovementStarted: {
            console.log("start:", currentIndex)
            currentItem.video.pause()
        }

    }

}

