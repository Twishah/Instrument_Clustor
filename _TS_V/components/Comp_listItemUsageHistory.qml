/******************************************************************************
 * ListItemUsageHistory menuitem
******************************************************************************/

import QtQuick 2.11
import QtGraphicalEffects 1.0

Rectangle {
    id: backgroundRow

    property string dateStr: ""
    property string timeStr: ""
    property string hourMeterHistoryStr: ""
    property bool isCurrent: false

    width: 272
    height: 43
    color: color_gray
    border {
        color: isCurrent ? color_blue : color_gray_bar
        width: 1
    }

    Text {
        id: dateText
        color: color_white
        font.pixelSize: 17
        font.family: systemFont
        anchors {
            left: parent.left
            leftMargin: 7
            verticalCenter: parent.verticalCenter
        }
        text: dateStr
    }

    Text {
        id: timeText
        color: color_white
        font.pixelSize: 17
        font.family: systemFont
        anchors {
            left: dateText.right
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
        text: timeStr
    }

    Text {
        id: hourMeterHisText
        color: color_white
        font.pixelSize: 17
        font.family: systemFont
        anchors {
            right: parent.right
            rightMargin: 7
            verticalCenter: parent.verticalCenter
        }
        text: hourMeterHistoryStr
    }
}
