import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Page{
    id: mePage
    visible: true
    width: 360
    height: 640
    title: qsTr("User")
    property alias writeMeaasge: writeMessage
//    color: "red"
    ColumnLayout{

        RowLayout{
            HeadImage{
                id: head_image
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 10
                anchors.leftMargin: 10
            }
            Button{
                id: writeMessage
                text: "编辑资料"
                anchors.left:head_image.right
                anchors.leftMargin: 40
                anchors.verticalCenter: head_image.verticalCenter
            }
            Button{
                id: addFriend
                text: "+好友"
                anchors.left: writeMessage.right
                anchors.leftMargin: 20
                anchors.verticalCenter: head_image.verticalCenter
            }
        }
        ColumnLayout{
            Text {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 15
                anchors.leftMargin: 10
                id: username
                text: client.user().getUsername()
                font.pixelSize: 30
            }
            Text {
                anchors.top: username.bottom
                anchors.topMargin: 2
                anchors.left: parent.left
                anchors.leftMargin: 10
                id: uaername
                text: "抖音号: " + client.user().getId()
                font.pixelSize: 15
            }
            Rectangle{
                anchors.top: uaername.bottom
                anchors.topMargin: 2
                id: rec1
                width: mePage.width
                height: 1
                color: "blue"
            }

            Text {
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: rec1.bottom
                anchors.topMargin: 5
                id: uaernam
                width: mePage.width
                text: "个人简介:"+client.user().getIntroduce()
                font.pixelSize: 20
                wrapMode: Text.WrapAnywhere
            }
            RowLayout{

                id: icon

                Rectangle{
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                    id:label1
                    width: 50
                    height: 25
                    Text {
                        anchors.centerIn: parent
                        id: name1
                        text: qsTr("text")
                    }
                }

                Rectangle{
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    anchors.left: label1.right
                    anchors.leftMargin: 10
                    id:label2
                    width: 50
                    height: 25
                    Text {
                        anchors.centerIn: parent
                        id: name2
                        text: qsTr("text")
                    }
                }

                Rectangle{
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    anchors.left: label2.right
                    anchors.leftMargin: 10
                    id:label3
                    width: 50
                    height: 25
                    Text {
                        anchors.centerIn: parent
                        id: name3
                        text: qsTr("text")
                    }
                }
            }
            Rectangle{
                anchors.top: icon.bottom
                anchors.topMargin: 30
                id: rec2
                width: mePage.width
                height: 1
                color: "blue"
            }
            Main{
                anchors.top: parent.top
                anchors.topMargin: 210
            }
        }

    }

}

