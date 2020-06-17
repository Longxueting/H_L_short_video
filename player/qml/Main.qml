import Felgo 3.0
import QtQuick 2.0
import QtMultimedia 5.12
import JsonData 1.0

App{

    onInitTheme: {
        // Set the navigation bar background to a shiny blue
        Theme.navigationBar.backgroundColor = "blue"
        Theme.navigationBar.titleColor = "black"

        // Set the global text color to a dark blue
        Theme.colors.textColor = "#000080"
    }

    property var main : []

//    function readURL()
//    {
////        var j=0;
//        for(var i=0; i<jsonData.count; i++){
//            main[i] = jsonData.at[i].toObject()
//        }
//    }

    Navigation {
        id: navigation
        navigationMode: navigationModeDrawer
        //navigationMode: navigationModeDrawer

        NavigationItem {
            title: "Main"
            icon: IconType.heart
            id: homeitem

            NavigationStack {


                Page {
                    id: mainPage
                    navigationBarHidden: true
                    property var stopPlay: pathview.currentItem.video_hl
                    //property var showImage: pathview.currentItem.image_hl

                    JsonDataMain{
                        id:jsondata
                    }

                    JsonListModel {
                        id: jsonmodel
                        source: jsondata.jsonData
                        keyField: "id"
                    }

                    PathView {
                        id:pathview
                        anchors.fill: parent
                        pathItemCount: 5
                        //cacheItemCount: 2
                        model: jsonmodel//ContactModel {}
                        delegate: Rectangle {
                            id: delegate
                            width: mainPage.width
                            height: mainPage.height
                            property alias video_hl: video
                            //property alias image_hl: image

                            MediaPlayer {
                                id: video
                                autoPlay: false
                                loops: MediaPlayer.Infinite
                                source: jsonmodel.get(index).video_source/*jsondata.jsonData[index].video_source*/
                            }

                            VideoOutput {
                                id: play
                                anchors.fill: parent
                                fillMode: VideoOutput.PreserveAspectFit
                                source: video
                                MouseArea{
                                    anchors.fill: parent
                                    onClicked: {
                                        video.playbackState === MediaPlayer.PlayingState ? video.pause(): video.play()
//                                        if(image.visible == true){
//                                            image.visible = false
//                                        }
                                    }
                                    onCanceled: {
                                        video.pause()
                                        //image.visible = true
                                        video.seek(video.position-50000)
                                    }
                                }

                            }
//                            Image {
//                                id: image
//                                source: picture
//                                anchors.fill: parent
//                                visible: true
//                            }

                        }
                        path: Path {
                            startX: mainPage.width/2; startY: mainPage.height/2
                            PathLine { x: mainPage.width/2; y: mainPage.height*1.5}
                            PathLine { x: mainPage.width/2; y: mainPage.height*3.5}
                            PathLine { x: mainPage.width/2; y: mainPage.height*3.5}
                            PathLine { x: mainPage.width/2; y: mainPage.height*1.5}
                        }
                        onCurrentIndexChanged: {
                            //currentItem.image_hl.visible = false
                            currentItem.video_hl.play()
                        }
                    }
                }
                Connections{
                    target: homeitem
                    onSelected:{
                        //mainPage.showImage.visible = false
                        mainPage.stopPlay.play()
                    }
                }
            }
        }


        NavigationItem {
            title: "Second"
            icon: IconType.thlarge

            NavigationStack {

                Page {
                    title: "Second Page"

                }
            }
        }
    }
}

