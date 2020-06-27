import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    anchors.fill: parent
    width: 360
    height: 640
    property int itemSelected: 0

    header: Rectangle{
        height: 50
        color: "grey"
        Rectangle {
            id: tool
            height: 50
            width: 50
            color: "grey"
            Label {
                anchors.centerIn: parent
                id: toolButton
                text: "<"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
            }
            MouseArea{
                anchors.fill: parent
                onClicked: stackView.pop()
            }
        }
        Label{
            anchors.centerIn: parent
            text: "bianjiziliao"
        }
    }

    Rectangle{
        id: touxiang
        height: 200
        width: 360
        HeadImage{
            anchors.centerIn: parent
        }
    }

    Rectangle{
        height: 600
        width: 360
        anchors.top: touxiang.bottom
        anchors.topMargin: 10
        Column{
            MessageItem{
                id: item1
                itemClick.onClicked: {
                    itemSelected = 0
                    stackView.push(view)
                }
            }
            MessageItem{
                id: item2
                itemClick.onClicked: {
                    itemSelected = 1
                }
            }
            MessageItem{
                id: item3
                itemClick.onClicked: {
                    itemSelected = 2
                }
            }
            MessageItem{
                id: item4
                itemClick.onClicked: {
                    itemSelected = 3
                }
            }
            MessageItem{
                id: item5
                itemClick.onClicked: {
                    itemSelected = 4
                }
            }
            MessageItem{
                id: item6
                itemClick.onClicked: {
                    itemSelected = 5
                }
            }
            MessageItem{
                id: item7
                itemClick.onClicked: {
                    itemSelected = 6
                }
            }
        }
    }

    Component{
        id: view
        ChangeMessage{
        }
    }
}
