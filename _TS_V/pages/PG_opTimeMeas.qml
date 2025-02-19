import QtQuick 2.0
import MyQmlModule 1.0
import QtGraphicalEffects 1.0
import "../components"

Item {
    id: opTimeMeasID
    height: 320
    width: 240
    anchors.topMargin: backEnd.currentConfig.headerHeight

    property string resultDate: ""
    property string resultTime: ""
    property string resultHourmeterDiff: ""

    property bool is12HourFormat: dm.formatHour === 1 ? true : false

    Rectangle {
        width: parent.width
        height: parent.height
        color: color_gray
    }

    onVisibleChanged:
    {
        resultDate = dm.getOpTimeResetDate()

        if(is12HourFormat)
        {
            var timeStrList = dm.getOpTimeResetTime().split(':')
            var amPm = parseInt(timeStrList[0]) >= 12 ? " PM" : " AM"
            var mins = timeStrList[1]
            var hour = parseInt(timeStrList[0]) % 12
            if (hour === 0) {
                hour = 12;
            }
            resultTime = hour + ":" + mins + amPm
        }
        else {
            resultTime = dm.getOpTimeResetTime()
        }

        var hourmeterAtReset = dm.getOpTimeResetHourmeter()
        resultHourmeterDiff = dataEngine.opHours_Total.value > hourmeterAtReset ? (dataEngine.opHours_Total.value - hourmeterAtReset).toFixed(1) : 0
    }

    function menuPressed()
    {        
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        // View Operational management page
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = qsTrId("LBL_0038") + translator.emptyString
        pg_largeList.visible = true
        pg_opTimeMeas.visible = false
        backEnd.setState(MyAppState.OP_MANAGEMENT)
        backEnd.setCurrentPage(pg_largeList)
    }

    function upPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }
    }

    function downPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }
    }

    function enterPressed()
    {
        if (startupInfo.isManualStartMode()) {
            pg_home2.restartTimeoutTimer()
        }

        console.log("Reset Op Time page selected")
        backEnd.setCurrentPage(pg_listIcon)
        pg_listIcon.selectResetOpTimeMeasureModel()
        pg_listIcon.visible = true

        pg_opTimeMeas.visible = false
        pgHeader.visible = true
        pgHeader.mainMenu = false
        pgHeader.titleString = qsTrId("LBL_0053") + translator.emptyString
    }

    Rectangle {
        id: headerRect
        width: parent.width + 2// - comp_navigationBar.width
        height: 67
        color: color_gray
        border.width: 2
        border.color: color_gray_bar
        x: 0
        anchors {
            top : parent.top
            topMargin: 0
        }
        Image {
            id: icon
            source: "qrc:/graphics/OperationalManagementMode/7.65 Operation time measurement - white.png"
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            fillMode: Image.Pad
        }
    }

    Rectangle {
        id: middleRect
        width: parent.width + 2// - comp_navigationBar.width
        height: 110
        color: color_gray
        border.width: 2
        border.color: color_gray_bar
        x: 0
        anchors {
            top : headerRect.bottom
            topMargin: -2
        }

        Text {
            id: lastResetText
            color:  "white"
            font.pixelSize: 14
            font.family: systemFont
            anchors {
                top: parent.top
                topMargin: 10
                left: parent.left
                leftMargin: 10
            }
            text: qsTrId("LBL_0051") + translator.emptyString
        }

        Text {
            id: lastResetDatetimeText
            color:  "white"
            font.pixelSize: 16
            font.family: systemFont
            lineHeightMode: Text.ProportionalHeight
            lineHeight: 1.3
            anchors {
                top: lastResetText.bottom
                topMargin: 10
                left: lastResetText.left
                leftMargin: 20
            }
            text: qsTrId("LBL_0017") + translator.emptyString + " : " + resultDate + "\n"
               +  qsTrId("LBL_0018") + translator.emptyString + " : " + resultTime + "\n"
               +  qsTrId("LBL_0052") + translator.emptyString + " " + resultHourmeterDiff + "h"
        }
    }

    Rectangle {
        id: lowerRect
        width: parent.width + 2// - comp_navigationBar.width
        height: parent.height - middleRect.height - headerRect.height + middleRect.border.width + headerRect.border.width
        color: color_gray
        border.width: 2
        border.color: color_gray_bar
        x: 0
        anchors {
            top : middleRect.bottom
            topMargin: -2
        }

        Rectangle {
            id: resetRect
            width: 0.5*parent.width
            height: parent.height
            color: color_blue
            border.width: 2
            border.color: color_gray_bar
            anchors {
                top : lowerRect.top
                right: lowerRect.right
            }

            Text {
                id: resetText
                color:  "white"
                font.pixelSize: 14
                font.family: systemFont
                anchors {
                    verticalCenter: resetRect.verticalCenter
                    horizontalCenter: resetRect.horizontalCenter
                }
                text: qsTrId("LBL_0053") + translator.emptyString
            }
        }
    }
}
