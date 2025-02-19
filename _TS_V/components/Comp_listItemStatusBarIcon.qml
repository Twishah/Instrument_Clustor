/******************************************************************************
 * ListItemStatusBar menuitem
******************************************************************************/

import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: backgroundRow

    property bool isCurrent: false
    property int outlineThick: 1
    property string iconPict: ""
    property string titleText: "ERROR"
    property bool isSOH: false
    property int fontSize: 17
    property bool isTemperature: false
    property bool iconIsText: false
    property string textAsIcon: ""
    property int textAsIconLeftMargin: 15
    property bool textVisible: true

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

        Rectangle {
            id: alignRect
            color: "transparent"
            width: iconIsText ? 17 : 77
            height: parent.height
            anchors {
                left: parent.left
                leftMargin: iconIsText ? 10 : 20
            }
        }

        Image {
            id: iconStatusBar
            anchors {
                verticalCenter: alignRect.verticalCenter
                horizontalCenter: alignRect.horizontalCenter

            }
            fillMode: Image.Pad
            source: !isSOH ? iconPict : ""
            visible: !isSOH
        }

        Text {
            id: iconStatusBarText
            color: color_white
            font.pixelSize: 20
            font.family: systemFont
            anchors {
                horizontalCenter: alignRect.horizontalCenter
                verticalCenter: alignRect.verticalCenter
            }
            text: iconPict
            visible: isSOH
        }

        Text {
            id: iconStatusBarText2
            color: color_white
            font.pixelSize: 18
            font.family: systemFont
            anchors {
                left: parent.left
                leftMargin: textAsIconLeftMargin
                verticalCenter: parent.verticalCenter
            }
            text: textAsIcon
            visible: iconIsText
        }
    }

    Rectangle {
        id: rectRight
        width: 83
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
            id: textStatusBar
            color:  color_white
            font.pixelSize: fontSize
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: titleText
            visible: textVisible
        }
    }
}
