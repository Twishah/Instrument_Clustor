/******************************************************************************
 * ListItemLargeListSelection menuitem
******************************************************************************/

import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: backgroundRow

    property string sourcePicture: ""
    property bool isCurrent: false
    property bool isSelected: false
    property int outlineThick: 1

    width: 268
    height: 69
    color: isCurrent ? color_blue : "transparent"

    Image {
        id: checkboxIcon

        anchors {
            left: parent.left
            leftMargin: 25
            verticalCenter: parent.verticalCenter
        }
        fillMode: Image.Pad
        source: isSelected ? "qrc:/graphics/PtoSettings/7.46 Selection light ON.png" : "qrc:/graphics/PtoSettings/7.47 Selection light OFF.png"
    }

    Item {
        id: test

        height: parent.height
        width: 70
        anchors {
            right: parent.right
            rightMargin: 25
        }
        Image {
            id: logo

            fillMode: Image.Pad
            source: sourcePicture
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
