import QtQuick 2.2

Item
{
    id: sc2tvDelegate
    property bool hovered
    Rectangle
    {
        id: streamDelegateRect
        width: 280
        height: 190
        color: "#002e76"
        anchors.margins: 0
        anchors.verticalCenter: parent.verticalCenter
        visible: true
        scale:  hovered ? 1.2 : 1.0
        z: hovered ? 1000 : 1
        MouseArea
        {
            id: itemArea
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                sc2tvDelegate.hovered = true;
            }
            onExited: {
                sc2tvDelegate.hovered = false;
            }
            onClicked:
            {
                stream.prepare(model.path)
                currentItem = model.id
            }
        }
        border
        {
            color: model.id==currentItem ? "green" : "white"
            width: 1
        }
        Image
        {
            anchors.margins: 7
            anchors.fill: parent
            source: model.img
        }
        Rectangle
        {
            id: streamerNameRect
            height: 20
            color: "#002e76"
            opacity: 0.8
            border.color: "#000000"
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            Text
            {
                id: streamerNameText
                color: "#ffffff"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                text: model.streamer_name
                width: parent.width
                font.family: "Times New Roman"
                font.pointSize: 13
                wrapMode: Text.WordWrap
            }
        }
        Rectangle
        {
            id: streamNameRect
            height: 60
            color: "#002e76"
            opacity: 0.8
            border.color: "#000000"

            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter

            Text
            {
                id: streamNameText
                color: "#ffffff"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                text: model.title
                width: parent.width
                font.family: "Times New Roman"
                font.pointSize: 13
                wrapMode: Text.WordWrap
            }
        }
        Rectangle
        {
            id: streamRatingRect
            width: 60
            height: 20
            color: "#002e76"
            opacity: 0.8
            border.color: "#000000"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            Text
            {
                id: streamRatingText
                color: "#ffffff"
                verticalAlignment: Text.AlignBottom
                text: model.rating
                width: parent.width
                font.family: "Times New Roman"
                font.pointSize: 13
                wrapMode: Text.WordWrap
            }
        }
    }
}

