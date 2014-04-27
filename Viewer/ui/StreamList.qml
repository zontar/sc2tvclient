import QtQuick 2.2

Rectangle {
    id: mainRect
    color: "#000000"
    property var currentItem

    ListView
    {
        id: streamList
        anchors.fill: parent
        anchors.margins: 0
        spacing: 4
        model: StreamModel
        delegate: Qt.createComponent(StreamModel.getRelatedDelegate())
        clip: true
        orientation: ListView.Horizontal
    }
}
