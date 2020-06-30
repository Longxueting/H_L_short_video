import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: mePage
    visible: true
    width: 360
    height: 640
    //title: qsTr("User")
    property string guanzhuSource
    property var loader: loader_id

    function changePage() {
        loader_id.source = "GuanzhuVideo.qml"
        if(loader_id.status == Loader.Loading){
                console.log("is Loading")
        }
    }

    Rectangle{
        anchors.fill: parent
        color: "black"
        ListModel{
            id: gridModel
            ListElement{
                image: "file:///root/01.png"
                video: "rtmp://127.0.0.1/vod/01.mp4"
            }
            ListElement{
                image: "file:///root/02.png"
                video: "rtmp://127.0.0.1/vod/02.mp4"
            }
            ListElement{
                image: "file:///root/03.png"
                video: "rtmp://127.0.0.1/vod/03.mp4"
            }
            ListElement{
                image: "file:///root/04.png"
                video: "rtmp://127.0.0.1/vod/04.mp4"
            }
            ListElement{
                image: "file:///root/05.png"
                video: "rtmp://127.0.0.1/vod/05.mp4"
            }
        }

        GridView{
            id:myfavorite
            model: gridModel
            snapMode: GridView.NoSnap
            clip: true

            anchors.fill:parent
            width: mePage.width
            height: mePage.height
            cellWidth: mePage.width/2
            cellHeight: cellWidth*1.2+50
            delegate: contactDelegate
            focus: true
        }
        Component{
            id:contactDelegate
            Rectangle{
                width: myfavorite.cellWidth
                height: myfavorite.cellHeight
                border.color: "black"
                color: "black"
                Image {
                    id: favoritepicture
                    width: myfavorite.width/2.03
                    height: width*1.2
                    source: image
                }
                Rectangle{
                    width: myfavorite.width/2.03
                    anchors.top: favoritepicture.bottom
                    height: 50
                    color: "#222222"
                    Label{
                        anchors.fill: parent
                        text: "zhe shi shipin de wenzi miaoshu!"
                        wrapMode: Text.Wrap
                        color: "white"
                    }
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        guanzhuSource = video
                        changePage()
                    }
                }
            }
        }
    }
    Loader{
        id: loader_id
        anchors.fill: parent
        asynchronous: true
    }

}
