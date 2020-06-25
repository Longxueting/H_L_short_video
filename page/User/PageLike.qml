import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page Like")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ListView{
        anchors.fill: parent
        model: 50
        delegate: Rectangle{
            height: 20
            width: parent.width
            Text {
                id: text
                text: index
            }
        }
    }
}
