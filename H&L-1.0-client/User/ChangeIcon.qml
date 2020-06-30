import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    id: changeIcons
    anchors.fill: parent
    width: 360
    height: 640
    property var icons: []
    property var iconsNum: 0


    header: Rectangle{
        height: 50
        color: "black"
        Rectangle {
            id: tool
            height: 50
            width: 50
            color: "black"
            Label {
                anchors.centerIn: parent
                id: toolButton
                text: "<"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                color: "white"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: stackView.pop()
            }
        }
        Label{
            anchors.centerIn: parent
            text: "xuanzebiaoqian"
            color: "white"
        }

    }

    function deleteIcon(i){
        var index = icons.indexOf(i);
        icons.splice(index, 1)
    }

    ListModel{
        id: gridModel
        ListElement{
            icon : "萌宠"
        }
        ListElement{
            icon : "搞笑"
        }
        ListElement{
            icon : "治愈"
        }
        ListElement{
            icon : "风景"
        }
        ListElement{
            icon : "萌娃"
        }
        ListElement{
            icon : "明星"
        }
        ListElement{
            icon : "二次元"
        }
        ListElement{
            icon : "动漫"
        }
        ListElement{
            icon : "美食"
        }
        ListElement{
            icon : "体育"
        }
    }

    GridView{
        id: gridView
        model: gridModel
        snapMode: GridView.NoSnap
        clip: true
        anchors.left: parent.left
        anchors.leftMargin: 10
        width: changeIcons.width
        height: changeIcons.height
        cellWidth: changeIcons.width/2.02
        cellHeight: cellWidth*0.4
        delegate: contactDelegate
        focus: true
        header: Rectangle{
            height: 40
            width: parent.width
            Label{
                id: headLabel
                text: "只能添加三个标签~~~~"
                anchors.centerIn: parent
            }
        }
        footer: Rectangle{
            height: 40
            color: "red"
            width: parent.width
            Label{
                text: "保存标签"
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    iconText = icons[0] + "," + icons[1] + "," + icons[2]
                    stackView.pop()
                }
            }

        }
    }

    Component{
        id: contactDelegate
        Rectangle{
            id: myIcon
            width: changeIcons.width/2.2
            height: (changeIcons.width/2.02) * 0.3
//            anchors.centerIn: parent
            color: index%3 == 0 ? "#cceeff" : "#ccccff"
            radius: 15
            border.color: "#00ddff"
            Label{
                text: icon
                anchors.centerIn: parent
                id: iconLabel
                font.pixelSize: Qt.application.font.pixelSize * 1.0
                color: "#880000"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(myIcon.border.color == "#0000cc"){
                        deleteIcon(icon)
                        iconsNum--
                        myIcon.border.color = "#00ddff"

                    }else if(iconsNum < 3){
                            icons.push(icon)
                            iconsNum++
                            myIcon.border.color = "#0000cc"
                    }
                }
            }
        }
    }
}
