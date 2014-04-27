import QtQuick 2.2

Rectangle {
    id: mainRect
    color: "#000000"
    property var currentItem

    property var modelDelegate: Qt.createComponent("qrc:///sc2tv/Sc2tvDelegate.qml")
    ListView
    {
        id: streamList
        anchors.fill: parent
        anchors.margins: 0
        spacing: 4
        model: StreamModel
        delegate: modelDelegate
        clip: true
        orientation: ListView.Horizontal
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log(StreamModel.getRelatedDelegate())
            }
        }
    }
}
