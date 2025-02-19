/******************************************************************************
 * ListItemLineStatusBar menuitem
******************************************************************************/

import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: backgroundRow

    property bool isCurrent: false
    property bool isSelected: false
    property int outlineThick: 1
    property string iconPict: ""
    property string titleText: ""

    width: 273
    height: 43
    color: isCurrent ? color_blue : color_gray//color_gray_bar


    Rectangle {
        id: rectLeft
        width: backgroundRow.width - rectRight.width
        height: backgroundRow.height
        color: isCurrent ? color_blue : color_gray
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
        border {
            color: isCurrent ? color_blue : color_gray_bar
            width: outlineThick
        }

        Image {
            id: checkboxIcon
//            height: parent.height
//            width: height
            anchors {
                left: parent.left
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }
            fillMode: Image.Pad
            source: isSelected ? "qrc:/graphics/PtoSettings/7.46 Selection light ON.png" : "qrc:/graphics/PtoSettings/7.47 Selection light OFF.png"
            }

        Text {
            id: itemText
            color: color_white
            font.pixelSize: 16
            font.family: systemFont
            anchors {
                left: checkboxIcon.right
                leftMargin: 12
                verticalCenter: parent.verticalCenter
            }
            text: titleText
        }
    }

    Rectangle {
        id: rectRight
        width: 63
        height: backgroundRow.height
        color: color_gray
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
        border {
            color: isCurrent ? color_blue : color_gray_bar
            width: outlineThick
        }

        Image {
            id: logo
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
            source: iconPict
            fillMode: Image.Pad
        }
    }
}
