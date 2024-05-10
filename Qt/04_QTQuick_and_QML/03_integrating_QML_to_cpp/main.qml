import QtQuick 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Hello World")

    Text {
        text: myObject.message
        anchors.centerIn: parent
    }
}