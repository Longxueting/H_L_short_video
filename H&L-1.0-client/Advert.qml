import QtQuick 2.0
import QtQuick.Controls 2.12

Page {

    width: 360
    height: 640

    property  var i : -1

    function getRandomNum(Min,Max){
        var Range = Max - Min;
        var rand = Math.random();
        return(Min + Math.round(rand * Range));
    }
    Image {
        id: advert
        anchors.fill: parent
    }
    Component.onCompleted: {
        i = getRandomNum(0, 1)
        if(i === 0){
            advert.source = "qrc:/Image/advert1.jpg"
        }else{
            advert.source = "qrc:/Image/advert2.jpg"
        }
    }

    Timer{
        interval: 5000
        running: true
        onTriggered: {
            load_id.source = "Subject.qml"
        }
    }

    Loader{
        id: load_id
        asynchronous: true
    }

}
