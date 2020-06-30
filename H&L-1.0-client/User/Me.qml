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
    property alias stackView: stackView

    StackView {
        id: stackView
        initialItem: mypage
        anchors.fill: parent
    }

    MyPage{
        id: mypage
        writeMeaasge.onClicked: {
            stackView.push(view)
        }
    }

    Component{
        id:view
        Message{
            id: message
        }
    }

    Component{
        id: view1
        PageLike{
            id: myPageLike
        }
    }

}

