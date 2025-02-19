/******************************************************************************
 * ListItem menuitem
******************************************************************************/

import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: listItem

    property bool isCurrent: false
    property string sourceIcon: ""
    property string title: ""

    width: 270
    height: 69
    color: isCurrent ? color_blue : color_gray

    Item  {
        id: itemIconbackground

        width: 61
        height: parent.height
        anchors {
            left: parent.left
            leftMargin: 8
        }
        Image {
            id: itemIconPicture

            fillMode: Image.Pad
            source: sourceIcon
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
            visible: sourceIcon === "" ? false : true
        }
    }

    Text {
        id: itemText

        width: sourceIcon === "" ? 245 : 185
        height: parent.height
        text: title
        color: color_white
        font.pixelSize: 18
        font.family: systemFont
        elide: Text.ElideRight
        wrapMode: Text.WordWrap
        anchors {
            left: parent.left
            leftMargin: sourceIcon === "" ? 20 : 80
            verticalCenter: parent.verticalCenter
        }
        verticalAlignment: Text.AlignVCenter
    }
}
