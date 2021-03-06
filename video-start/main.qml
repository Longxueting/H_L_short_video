import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12
//import JsonData 1.0

ApplicationWindow {
    id: mainPage
    visible: true
    width: 400
    height: 680
    title: qsTr("My video player")
    property string applicationDirPath
    property var classifyTable
    property int videoIndex:0

    ListModel{
        id: videoModel1
        ListElement{
            imageSource: "file:///root/myVideo/vod/01.png"
            videoSource: "file:///root/receiver/receive1.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/02.png"
            videoSource: "file:///root/receiver/receive2.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/03.png"
            videoSource: "file:///root/receiver/receive3.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/04.png"
            videoSource: "file:///root/receiver/receive4.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/05.png"
            videoSource: "file:///root/receiver/receive5.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/01.png"
            videoSource: "file:///root/receiver/receive1.flv"
        }
        ListElement{
            imageSource: "file:///root/myVideo/vod/02.png"
            videoSource: "file:///root/receiver/receive2.flv"
        }
    }

    Component{
        id: delegate
        Rectangle{
            id:rectangle
            width: mainPage.width
            height: mainPage.height
            property alias video: video

            Rectangle{  //进度条
                id: progressBar
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                //width: parent.width
                height: 1
                width: video.duration > 0?parent.width*video.position/video.duration : 0     //position保存当前播放的位置
                color: "white"
                z:2

            }

            Image {
                id: image
                width: mainPage.width
                height: mainPage.height
                source: imageSource
            }
            Video{
                id: video
                anchors.fill: parent
                fillMode: VideoOutput.Stretch
                visible: true
                source: videoSource/*"file:///root/myVideo/01.mp4"*/
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
            }
//            Image {
//                id: is_like
//                source: "/Image/icon_home_like_after.png"
//                width: 60
//                height: 60
//                visible: true
//                anchors.right: parent.right
//                anchors.top: parent.top
//                anchors.topMargin: 330
//                anchors.rightMargin: 15
//            }
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
        model: videoModel1
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

        Component.onCompleted: {
            //positionViewAtIndex(1, ListView.Beginning)
            videoplay.VideoInit()
            videoIndex=1
            currentItem.video.play()
        }
        onMovementStarted: {
            startCurrent=currentIndex;
            console.log("start:", currentIndex)
            currentItem.video.pause()
        }


        onCurrentItemChanged: {
            //currentItem.video.pause()
        }

    }

}

