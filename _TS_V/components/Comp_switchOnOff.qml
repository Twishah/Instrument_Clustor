import QtQuick 2.0

Rectangle {
    id: activateContainer

    property bool onOff: false

    width: parent.width
    height: 70
    color: parent.color

    Rectangle {
        id: levelRect

        width: 0.45 * parent.width
        height: 30
        color: color_blue
        border {
            color: color_blue
            width: 2
        }
        anchors {
            leftMargin: 5
            left: parent.left
            bottom: parent.bottom
            bottomMargin: levelRect.height
        }

        Text {
            id: selectionLevelText
            color: color_white
            font.pixelSize: 14
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: qsTrId("LBL_0066") + translator.emptyString
        }
    }

    Rectangle {
        id: onRect

        width: 0.2 * parent.width
        height: levelRect.height
        color: onOff ? color_blue : color_gray  // to navigate after OK
        border {
            color: onOff ? color_blue : color_gray_bar  // to navigate after OK
            width: 2
        }
        anchors {
            leftMargin: 10
            left: levelRect.right
            bottom: levelRect.bottom
            bottomMargin: levelRect.bottomMargin
        }

        Text {
            id: onText
            color: color_white
            font.pixelSize: 20
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: "ON"
        }
    }

    Rectangle {
        id: offRect

        width: onRect.width
        height: levelRect.height
        color: !onOff ? color_blue : color_gray // to navigate after OK
        border {
            color: !onOff ? color_blue : color_gray_bar  // to navigate after OK
            width: 2
        }
        anchors {
            leftMargin: 5
            left: onRect.right
            bottom: levelRect.bottom
            bottomMargin: levelRect.bottomMargin
        }

        Text {
            id: offText
            color: color_white
            font.pixelSize: 20
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: "OFF"
        }
    }
}


