import QtQuick 2.12
import QtQuick.Controls 2.5
import QtMultimedia 5.12

Page {
    width: 360
    id: favoritepage
    property string videoSource

    ListModel{
        id: gridModel
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/01.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/02.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/03.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/04.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/05.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/06.mp4"
//        }
//        ListElement{
//            image: "qrc:/Image/01.png"
//            video: "rtmp://127.0.0.1/vod/07.mp4"
//        }
    }

    Rectangle{

        anchors.fill: parent
        color: "black"

        GridView{
            id:myfavorite
            model: gridModel
            snapMode: GridView.NoSnap
            clip: true
            anchors.fill:parent
            width: favoritepage.width
            height: favoritepage.height
            cellWidth: favoritepage.width/3.02
            cellHeight: cellWidth*1.2
            delegate: contactDelegate
            focus: true
//            footer: Rectangle{
//                height: 20
//                width: parent.width
//                Label{
//                    text: "niyijingdaodazuidibo~~"
//                    anchors.centerIn: parent
//                }
//            }
        }
        Component{
            id:contactDelegate
            Item{
                width: myfavorite.cellWidth
                height: myfavorite.cellHeight
                Image {
                    id: favoritepicture
                    width: myfavorite.width/3.03
                    height: width*1.2
                    source: image/*favoritePictureSource*/
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            //                        mediaplayer.mediaplayer.source = video
                            videoSource = video
                            stackView.push(view)

                        }
                    }
                }


                Image {
                    id:littleheart
                    source: "qrc:/Image/zan.png"
                    width: 20
                    height: 20
                    anchors.left: favoritepicture.left
                    anchors.leftMargin: 10
                    anchors.bottom: favoritepicture.bottom
                    anchors.bottomMargin: 10
                }
                Text {
                    text:"10"
                    color: "white"
                    anchors.left: littleheart.right
                    anchors.leftMargin: 5
                    anchors.bottom: littleheart.bottom
                }
            }
        }

        Component{
            id : view
            MyVideoPlay{
                id :mediaplayer
            }
        }
    }

}
