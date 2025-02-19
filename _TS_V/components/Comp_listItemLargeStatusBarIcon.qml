/******************************************************************************
 * ListItemLargeStatusBar menuitem
******************************************************************************/

import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: backgroundRow

    property bool isCurrent: false
    property int outlineThick: 1
    property string iconPict: ""
    property string leftText1: ""
    property string leftText2: ""
    property string rightText1: ""
    property string rightText2: ""

    width: 273
    height: 71
    color: isCurrent ? color_blue : color_gray

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
            id: iconStatusBar
            anchors.centerIn: parent
            fillMode: Image.Pad
            source: iconPict
        }
    }

    Rectangle {
        id: rectRight
        width: 193
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

        Text {
            id: dateText1
            color:  color_white
            font.pixelSize: 17
            font.family: systemFont
            anchors {
                left: parent.left
                leftMargin: 5
                top: parent.top
                topMargin: 12
            }
            text: leftText1
        }
        Text {
            id: hourmeterText1
            color:  color_white
            font.pixelSize: 17
            font.family: systemFont
            anchors {
                right: parent.right
                rightMargin: 5
                top: parent.top
                topMargin: 12
            }
            text: rightText1
        }

        Text {
            id: dateText2
            color:  color_white
            font.pixelSize: 17
            font.family: systemFont
            anchors {
                left: parent.left
                leftMargin: 5
                bottom: parent.bottom
                bottomMargin: 12
            }
            text: leftText2
        }
        Text {
            id: hourmeterText2
            color:  color_white
            font.pixelSize: 17
            font.family: systemFont
            anchors {
                right: parent.right
                rightMargin: 5
                bottom: parent.bottom
                bottomMargin: 12
            }
            text: rightText2
        }
    }
}
