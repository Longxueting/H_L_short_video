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
    Rectangle{
        anchors.fill: parent
        color: "black"
        ColumnLayout{

            RowLayout{
                HeadImage{
                    id: head_image
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 10
                    anchors.leftMargin: 10
                }
                Rectangle{
                    id: myMessage
                    radius: 10
                    width: 100
                    height: 40
                    anchors.left:head_image.right
                    anchors.leftMargin: 40
                    anchors.verticalCenter: head_image.verticalCenter
                    color: "#444444"
                    opacity: 0.8
                    Label{
                        text: "编辑资料"
                        anchors.centerIn: parent
                        color: "white"
                    }

                    MouseArea{
                        id: writeMessage
                        anchors.fill: parent
                    }

                }
                Rectangle{
                    id: addFriend
                    radius: 10
                    width: 80
                    height: 40
                    anchors.left: myMessage.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: head_image.verticalCenter
                    color: "#444444"
                    opacity: 0.8
                    Label{
                        text: "+好友"
                        anchors.centerIn: parent
                        color: "white"
                    }
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
                    color: "white"
                }
                Text {
                    anchors.top: username.bottom
                    anchors.topMargin: 2
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    id: uaername
                    text: "抖音号: " + client.user().getId()
                    font.pixelSize: 15
                    color: "white"
                }
                Rectangle{
                    anchors.top: uaername.bottom
                    anchors.topMargin: 2
                    id: rec1
                    width: mePage.width
                    height: 1
                    color: "#444444"
                }

                Text {
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: rec1.bottom
                    anchors.topMargin: 5
                    id: uaernam
                    width: mePage.width
                    text: "个人简介:"+ client.user().getIntroduce()
                    font.pixelSize: 20
                    wrapMode: Text.WrapAnywhere
                    color: "white"
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
                        color: "#444444"
                        opacity: 0.8
                        Text {
                            anchors.centerIn: parent
                            id: name1
                            text: client.user().get_tags()[0]
                            color: "#ffffff"
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
                        color: "#444444"
                        opacity: 0.8
                        Text {
                            anchors.centerIn: parent
                            id: name2
                            text: client.user().get_tags()[1]
                            color: "#ffffff"
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
                        color: "#444444"
                        opacity: 0.8
                        Text {
                            anchors.centerIn: parent
                            id: name3
                            text: client.user().get_tags()[2]
                            color: "#ffffff"
                        }
                    }
                }
                Rectangle{
                    anchors.top: icon.bottom
                    anchors.topMargin: 30
                    id: rec2
                    width: mePage.width
                    height: 1
                    color: "#444444"
                }
                Like{
                    anchors.top: parent.top
                    anchors.topMargin: 210
                }
            }
        }
    }
    onFocusChanged: uaernam.text="个人简介:"+ client.user().getIntroduce()
}

