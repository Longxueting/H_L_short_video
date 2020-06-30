import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    anchors.fill: parent
    width: 360
    height: 640
    //property alias toolButton: toolButton

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
            text: "修改信息"
            color: "white"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
        }
        Rectangle {
            id: tool2
            height: 50
            width: 50
            color: "black"
            anchors.right: parent.right
            Label {
                anchors.centerIn: parent
                id: toolButton2
                text: "保存"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                color: "white"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(itemSelected == 0){
                        nameText = textInput.text

                    }else if(itemSelected == 2){
                        client.changeIntroduce(textInput.text)
                        describeText = textInput.text

                    }
                    stackView.pop()
                }
            }
        }

    }
    Rectangle{
        anchors.fill: parent
        color: "black"
        Rectangle{
            id:line1
            width: parent.width
            height: 0.5
            color: "#666666"
        }
        Text {
            id: myname
            text: qsTr("个人简介")
            anchors.top: line1.bottom
            color: "white"
            opacity: 0.8
            anchors.topMargin: 5
        }
        Rectangle{
            id:inputText
            width: parent.width-20
            anchors.horizontalCenter: parent.horizontalCenter
            height: 200
            anchors.top: myname.bottom
            anchors.topMargin: 20
            //border.color: "black"
            color: "#444444"
            TextInput{
                id: textInput
                width: parent.width
                wrapMode: Text.Wrap
                anchors.margins: 5
                //selectedTextColor: "#f01414"
                font.pointSize: 15
                color: "white"
            }
        }
    }



    Component.onCompleted: {
        if(itemSelected == 0){
            textInput.text = client.user().getUsername()
        }else if(itemSelected == 2){
            textInput.text = client.user().getIntroduce()
        }
    }
}
