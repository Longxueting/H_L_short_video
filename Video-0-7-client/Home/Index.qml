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
                width: mainPage.width * 0.14
                height: width
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: mainPage.height * 0.47
                anchors.rightMargin: mainPage.width * 0.04
                MouseArea{
                    anchors.fill: not_like
                    onClicked: {
                        like.visible = true
                        notLike.visible = false
                        $Model.setLikeNum(index,videoIndex,1)
                    }
                }
            }
            Image {
                id: is_like
                source: "/Image/icon_home_like_after.png"
                width: mainPage.width * 0.14
                height: mainPage.width * 0.14
                visible: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: mainPage.height * 0.47
                anchors.rightMargin: mainPage.width * 0.04
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        like.visible = false
                        notLike.visible = true
                        $Model.setLikeNum(index,videoIndex,-1)
                    }
                }
            }
            Text{       //点赞人数
                id:hearttext
                text: hlLikeNum
                anchors.top: not_like.bottom
//                anchors.left: not_like.left
//                anchors.leftMargin: (not_like.width-hearttext.text.length)/3
                anchors.right:parent.right
                anchors.rightMargin: 15+is_like.width/2
                anchors.verticalCenter: is_like.verticalCenter
                color: "white"
            }

            Text {
                id: author
                text: "@ " + hlAuctorName
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 70
                anchors.left: parent.left
                anchors.leftMargin: 10
                color: "white"
                font.pixelSize: 25
            }

            Text {
                id: describe
                text: hlDescribe
                anchors.bottom: parent.bottom
                width: 200
                //elide: Text.ElideRight
                anchors.bottomMargin: 50
                anchors.left: parent.left
                anchors.leftMargin: 10
                color: "white"
                font.pixelSize: 15
            }

            Image {
                id: toTalk
                source: "/Image/pinglun (3).png"
                width: 40
                height: 40
                visible: true
                anchors.right: parent.right
                anchors.top: is_like.bottom
                anchors.topMargin: 35
                anchors.rightMargin: mainPage.width * 0.05
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
                width: 40
                height: 40
                visible: true
                anchors.right: parent.right
                anchors.top: toTalk.bottom
                anchors.topMargin: 40
                anchors.rightMargin: mainPage.width * 0.05
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
            if(videoIndex>1){
                if(startCurrent-currentIndex>0 && startCurrent-currentIndex!=4 ){
                    videoIndex--
                    videoplay.up_slide(currentIndex,videoIndex)
                    if(currentIndex == 0){
                        listview.contentY = 5*mainPage.height
                    }
                }
            }
            if(videoIndex==1){
                listview.contentY=0
                console.log("首页：",currentIndex)
            }
            console.log("当前视频:",videoIndex)
            currentItem.video.play()
            currentItem.video.seek(currentItem.video.position - 50000)
            $Model.set(currentIndex,videoIndex)
            if(currentItem.isLike === false){
                currentItem.like.visible = false
                currentItem.notLike.visible = true
            }else{
                currentItem.like.visible = true
                currentItem.notLike.visible = false
            }
        }

        onCurrentItemChanged: {
            if(currentItem.isLike === false){
                currentItem.like.visible = false
                currentItem.notLike.visible = true
            }else{
                currentItem.like.visible = true
                currentItem.notLike.visible = false
            }

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

