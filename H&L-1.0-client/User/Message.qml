import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    anchors.fill: parent
    width: 360
    height: 640
    property int itemSelected: 0
    property alias iconText: icons.textSetName2
    property alias nameText: name.textSetName2
    property alias describeText: describe.textSetName2
    property alias sexText: sex.textSetName2
    property alias ageText: age.textSetName2

    header: Rectangle{
        height: 50
        color: "black"
        width: 40
        Rectangle {
            id: tool
            height: 50
            width: 50
            color: "#222222"
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
            text: "编辑资料"
            color: "white"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
        }
    }

    Rectangle{
        color: "black"
        id: touxiang
        height: 200
        width: 360
        HeadImage{
            anchors.centerIn: parent
        }
    }
    Rectangle{
        id:line
        width: parent.width
        height: 1
        color: "#666666"
        anchors.top: touxiang.bottom
    }

    Rectangle{
        height: 600
        width: 360
        anchors.top: line.bottom
        color: "black"
        Column{
            MessageItem{
                id: name
                textSetName1: "名字"
                textSetName2: client.user().getUsername() + " >"
                itemClick.onClicked: {
                    itemSelected = 0
                    stackView.push(view)
                }
            }
            MessageItem{
                id: id
                textSetName1: "抖音号"
                textSetName2:client.user().getId()+ "  "
                itemClick.onClicked: {
                    itemSelected = 1
                }
            }
            MessageItem{
                id: describe
                textSetName1: "简介"
                textSetName2: client.user().getIntroduce()+ " >"
                itemClick.onClicked: {
                    itemSelected = 2
                    stackView.push(view)
                }
            }
            MessageItem{
                id: sex
                textSetName1: "性别"
                textSetName2: "保密 >"
                itemClick.onClicked: {
                    itemSelected = 3
                    stackView.push(view3)
                }
            }
            MessageItem{
                id: age
                textSetName1: "年龄"
                textSetName2: "更改年龄 >"
                itemClick.onClicked: {
                    itemSelected = 4
                    stackView.push(view4)
                }
            }
            MessageItem{
                id: place
                textSetName1: "地区"
                textSetName2: "添加地区 >"
                itemClick.onClicked: {
                    itemSelected = 5
                }
            }
            MessageItem{
                id: icons
                textSetName1: "标签"
//                textSetName2:
                itemClick.onClicked: {
                    itemSelected = 6
                    stackView.push(view2)
                }
            }
        }
    }

    Component{
        id: view
        ChangeMessage{
        }
    }
    Component{
        id: view2
        ChangeIcon{
        }
    }
    Component{
        id: view3
        ChangeSex{
        }
    }
    Component{
        id: view4
        ChangeAge{
        }
    }

    Component.onCompleted: {
        var s = client.user().get_tags()[0] + "," + client.user().get_tags()[1] + "," + client.user().get_tags()[2] + ""
        if(client.user().get_tags()[0] === undefined){
            s = "添加标签 >"
            icons.textSetName2 = s
        }else{
            icons.textSetName2 = s
        }
        if(client.user().getIntroduce() === ""){
            s = "添加个人简介 >"
            describe.textSetName2 = s
        }
    }
}
