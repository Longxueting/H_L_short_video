import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import user 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 520
    title: qsTr("Login")

    UserAndPassowrd{
        id: myuser
        onStatusChanged: {
            if(status === UserAndPassowrd.Becoming){
                console.log("It.s Becoming!")
                msg.text = "Becoming!"
            }else if(status === UserAndPassowrd.Checking){
                console.log("It.s Checking!")
            }else if(status === UserAndPassowrd.Logined){
                console.log("It.s Logined!")
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

    Column{
        id: all
        height: parent.height/2
        width: parent.width/2
        anchors.centerIn: parent

        Text {
            id: msg
            text: "myuser.msg"
        }

        Column{
            height: 80
            Text{
                id: user
                text: "Username"
                bottomPadding: 10
                font.pointSize: 10
                font.family: "Verdana"
            }
            TextField{
                id: userInput
                anchors.margins: 50
                width: all.width
                height: 40
                text: "Enter Username"
                font.italic: true
                renderType: Text.QtRendering
                horizontalAlignment: Text.AlignLeft
            }
        }

        Column{
            height: 80
            Text{
                id: pwd
                text: "Password"
                bottomPadding: 10
                font.pointSize: 10
            }
            TextField{
                id: pwdInput
                width: all.width
                height: 40
                text: "Enter Password"
                font.italic: true
            }
        }

        Row{
            id: row
            Button{
                id: register
                width: all.width/2
                text: "Register"
                onClicked: {
                    realUser.username = userInput.text
                    realUser.password = userInput.text
                    myuser.user = realUser
                }
            }
            Button{
                id: login
                text: "Login"
                width: all.width/2
                onClicked: {
                    realUser.username = userInput.text
                    realUser.password = userInput.text
                    myuser.user = realUser
                }
            }
        }
    }
}
