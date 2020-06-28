import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Item {
    id: mainPage
    visible: true
    width: 360
    height: 580
    //title: qsTr("My video player")
    property int videoIndex:0
    property var myVideo: listview.currentItem.video


    Component{
        id: delegate
        Rectangle{
            id: mainVideo
            width: mainPage.width
            height: mainPage.height
            property alias video: video
            property alias like: is_like
            property alias notLike: not_like
//            property alias myTalk: talkPage
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
                onStatusChanged: {
                    if(video.status === 8 && ListView.isCurrentItem){
                        console.log("shipinzhuangtai : ", video.status)
                        waitFives.running = true
                        video.play()
                    }
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        video.playbackState === MediaPlayer.PlayingState ? video.pause() : video.play()
                    }
                }
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
//                z:1
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
                MouseArea{
                    anchors.fill: parent
                    onClicked:{
                        talkPage.visible = true
                    }
                        //stackview.push("TalkPage.qml")
                }
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

    TalkPage{
        id: talkPage
        anchors.fill: parent
        visible: false
        z : 1
    }

    ListView{
        id:listview
        anchors.fill: parent
        model: $Model
        orientation: verticalLayoutDirection
        highlightRangeMode:ListView.StrictlyEnforceRange
        snapMode: ListView.SnapOneItem
        delegate: delegate
        property int startCurrent
        onMovementEnded: {
            console.log("end:",currentIndex)

            console.log("判断1:",startCurrent-currentIndex)
            currentItem.video.play()

            if(startCurrent-currentIndex<0){//下滑
                videoIndex++
                videoplay.down_slide(currentIndex,videoIndex)
                if(currentIndex == 6){
                    listview.contentY = mainPage.height
                }
            }
            console.log(startCurrent,currentIndex)
            console.log("判断2:",startCurrent-currentIndex)
            if(startCurrent-currentIndex>0 && startCurrent-currentIndex!=4){//上滑
                if(videoIndex==2){
                    listview.contentY=0
                }else{
                    videoIndex--
                    videoplay.up_slide(currentIndex,videoIndex)
                    if(currentIndex == 0){
                        listview.contentY = 5*mainPage.height
                    }
                }
            }
            console.log("当前视频:",videoIndex)
            currentItem.video.play()
            currentItem.video.seek(currentItem.video.position - 50000)
        }

        onCurrentItemChanged: {
            if(currentItem.isLike === false){
                currentItem.like.visible = false
            }
            $Model.set(currentIndex,videoIndex)
        }

        Component.onCompleted: {
//            videoplay.VideoInit()
            videoIndex=1
            waitFives.start()
        }

        onMovementStarted: {
            startCurrent=currentIndex;
            console.log("start:", currentIndex)
            currentItem.video.pause()
            talkPage.visible = false
        }

    }

    Timer{
        id: waitFives
        interval: 3000
        running: false
        onTriggered: {
            myVideo.play()
        }
    }

}

