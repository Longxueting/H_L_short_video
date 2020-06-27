import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import user 1.0


Page {
    visible: true
    width: 300
    height: 520
    //title: qsTr("Login")

    UserAndPassowrd{
        id: myuser
        onStatusChanged: {
            if(status === UserAndPassowrd.Changed){
                console.log("It.s Changed!")
                msg.text = "Changed!"
            }else if(status === UserAndPassowrd.Logined){
                console.log("It.s Logined!")
                msg.text = "It.s Logined!!"
                $Model.init()
                load_id.source = "Subject.qml"
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
//                text: "Enter Username"
                placeholderText:"Enter Username"
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
                echoMode: TextInput.Password
                placeholderText: "Enter Password"
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
                    realUser.password = pwdInput.text
                    myuser.user = realUser
                }
            }
            Button{
                id: login
                text: "Login"
                width: all.width/2
                onClicked: {
                    realUser.username = userInput.text
                    realUser.password = pwdInput.text
                    myuser.user = realUser
                    client.sendU(userInput.text, pwdInput.text)
                    var re = client.login_re()
                    if(re === 0){
                        console.log()
                        myuser.status = UserAndPassowrd.Logined
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
