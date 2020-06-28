import QtQuick 2.0
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 360
    height: 640

    Component{
        id: view1
        Login{}
    }

    StackView{
        id: stackView
        initialItem: view1
        anchors.fill: parent
    }

}
