import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import user 1.0


Page {
    visible: true
    width: 360
    height: 640
    //title: qsTr("Login")
    property alias loader: load_id
    property alias loginHeader: header
    header: Rectangle{
        id:header
        color: "black"
        width: 360
        height: 40
        Text {
            id: text
            text: qsTr("登录")
            anchors.centerIn: parent
            font.pixelSize: 20
            color: "white"
        }
    }

    UserAndPassowrd{
        id: myuserd
        onStatusChanged: {
            if(status === UserAndPassowrd.Changed){
                console.log("It.s Changed!")
                msg.text = "Changed!"
            }else if(status === UserAndPassowrd.Logined){
                console.log("It.s Logined!")
                header.visible = false
                $Model.init()
                videoplay.VideoInit()
                load_id.source = "Advert.qml"
                if(load_id.status === Loader.Loading){
                    console.log("is loading!!!")
                }

                //                stackView.pop()
                //                stackView.push(view2)
            }else if(status === UserAndPassowrd.Register){
                console.log("It.s Register!")
            }else if(status === UserAndPassowrd.PasswordError){
                console.log("It.s PasswordError!")
            }else if(status === UserAndPassowrd.NotUser){
                console.log("It.s NotUser!")
            }
        }
    }
    User{
        id: realUser
    }

    Rectangle{
        anchors.fill: parent
        color: "#DDDDDD"
        Rectangle{
            color: "#DDDDDD"
            id: all
            height: parent.height/2
            width: parent.width/2
            anchors.centerIn: parent

            Rectangle{
                id:user
                width: all.width
                height: 50
                anchors.top: all.top
                anchors.topMargin: 50
                color: "#DDDDDD"
                TextField{
                    id: userInput
                    anchors.margins: 50
                    width: all.width
                    height: 40
                    //text: "Username"
                    placeholderText: "Enter Username"
                    font.italic: true
                    renderType: Text.QtRendering
                    horizontalAlignment: Text.AlignLeft
                }
            }
            Rectangle{
                color: "#DDDDDD"
                id:password
                width: all.width
                height: 50
                anchors.top: user.bottom
                anchors.topMargin: 30
                TextField{
                    id: pwdInput
                    width: all.width
                    height: 40
                    //text: "Enter Password"
                    echoMode: TextInput.Password
                    placeholderText: "Enter Password"
                    font.italic: true
                }
            }
            Rectangle{
                color: "#DDDDDD"
                height: 30
                width: all.width
                anchors.top: password.bottom
                anchors.topMargin: 30
                Rectangle{
                    id: register
                    color: "#444444"
                    width: all.width*0.4
                    height: 40
                    anchors.left:parent.left
                    radius: 10
                    Text {
                        anchors.centerIn: register
                        text: qsTr("注册")
                        font.pixelSize: 15
                        color: "white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            realUser.username = userInput.text
                            realUser.password = userInput.text
                            myuserd.user = realUser
                        }
                    }
                }
                Rectangle{
                    id: login
                    color: "#444444"
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    width: all.width*0.4
                    height: 40
                    radius: 10
                    Text {
                        anchors.centerIn: login
                        text: qsTr("登录")
                        font.pixelSize: 15
                        color: "white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            realUser.username = userInput.text
                            realUser.password = pwdInput.text
                            myuserd.user = realUser
                            client.sendU(userInput.text, pwdInput.text)
                            var re = client.login_re()
                            if(re === 0){
                                console.log()
                                myuserd.status = UserAndPassowrd.Logined
                            }
                        }
                    }

                }
            }
        }
    }
    Loader{
        id: load_id
        asynchronous: true
    }
}
