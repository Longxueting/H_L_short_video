import QtQuick 2.0

Item {
    id: container
    width: 300; height: 300

    function loadButton() {
        var component = Qt.createComponent("CuanzhuVideo.qml");
        if (component.status === Component.Ready) {
            var button = component.createObject(container);
        }
    }

    Component.onCompleted: loadButton()

}
