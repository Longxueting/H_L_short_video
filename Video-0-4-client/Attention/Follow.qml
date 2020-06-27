import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Page{
    id: attention
    visible: true
    height: 640
    width: 360

    StackView{
        id: stackView
        initialItem: view1
        anchors.fill: parent
    }

    Guanzhu{
        id: view1
    }

}
