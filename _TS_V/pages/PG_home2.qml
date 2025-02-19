import QtQuick 2.6
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import "../components"
import MyQmlModule 1.0


Item {
    id: home2ID

    property string date: getDateString()
    property string hour: dateTimeManager.getCurrentTime()
    property string hourMeter: canError18FEE747 ? minHourMeterString
                                                 :  (dataEngine.opHours_Total.value > maxHourMeter ? maxHourMeterString
                                                                                                   : (dataEngine.opHours_Total.value < 0.0 ? "0.0"
                                                                                                                                           : dataEngine.opHours_Total.value.toFixed(1)))


    Component.onCompleted: {
        if (startupInfo.isManualStartMode()) {
            backEnd.setCurrentPage(pg_home2)
            timeoutTimer.start()
            pgHeader.visible = false
            comp_navigationBar.hideEnter = false
            comp_navigationBar.outsideMainMenu = false
        }
    }

    onVisibleChanged: {
        if (pg_home2.visible) {
            controller.stopAutoSwitch();
            pgHeader.visible = false
            comp_navigationBar.hideEnter = false
            comp_navigationBar.outsideMainMenu = false
        }
        else {
            if (startupInfo.isManualStartMode()) {
                if (!controller.isMechanicMode1 && !controller.isMechanicMode2) {
                    controller.startAutoSwitch();
                }
                // comp_navigationBar.outsideMainMenu = true;
            }
        }
    }

    function restartTimeoutTimer()
    {
        timeoutTimer.restart()
    }

    function getDateString() {
        var dayValue = dateTimeManager.getDay() < 10 ? "0" + dateTimeManager.getDay().toString() : dateTimeManager.getDay().toString()
        var monthValue = dateTimeManager.getMonth() < 10 ? "0" + dateTimeManager.getMonth().toString() : dateTimeManager.getMonth().toString()
        var yearValue = dateTimeManager.getYear().toString()

        var date  = dayValue + "/" + monthValue + "/" + yearValue
        return date
    }

    function menuPressed() {
        timeoutTimer.restart()

        backEnd.setState(MyAppState.MENU_HOUR_METER)
        console.log("Menu page selected")
        pg_home2.visible = false;
        pg_menu.selectMenuItems();
        pg_menu.visible = true;
        backEnd.setCurrentPage(pg_menu);
        pgHeader.visible = false
        rectList.visible = false
        rectMenu.visible = true
    }

    function upPressed()
    {
        timeoutTimer.restart()
    }

    function downPressed()
    {
        timeoutTimer.restart()
    }

    function enterPressed()
    {
        timeoutTimer.restart()
    }

    Timer {
        id: timeTimer
        interval: 1000
        triggeredOnStart: true
        running: true
        repeat: true
        onTriggered: {
            hour = dateTimeManager.getCurrentTime()
        }
    }

    Timer { // BE2
        id: timeoutTimer
        interval: 120000
        triggeredOnStart: false
        running: false
        repeat: false
        onTriggered: {
            if(startupInfo.isManualStartMode())
            {
                RunProcess.launch("poweroff")
            }

        }
    }

    Rectangle {
        id: backgroundHome2
        anchors.fill: parent
        color: color_black

        Text {
            id: versionSW
            x: 7
            y: parent.height - 30
            text: version
            font.pixelSize: 15
            font.family: systemFont
            horizontalAlignment: Text.AlignLeft
            clip: true
            color: color_white
        }
    }

    Comp_chargeGauge { // BE2
        id: leftGauge
        x: 17
        y: 50
    }

    Rectangle {
        id: rectLine
        width: 125
        height: 1
        y: 81
        anchors.horizontalCenter: parent.horizontalCenter
        color: color_gray_bar
        visible: true
    }

    Column {
        id: col
        spacing: 25
        anchors.centerIn: parent

        Text {
            id: textDate
            anchors.horizontalCenter: parent.horizontalCenter
            text: date
            font.pixelSize: 28
            horizontalAlignment: Text.AlignHCenter
            clip: true
            color: color_white
        }

        Text {
            id: textHour
            anchors.horizontalCenter: parent.horizontalCenter
            text: hour
            font.pixelSize: 28
            font.family: systemFont
            horizontalAlignment: Text.AlignHCenter
            clip: true
            color: color_white
        }

        Rectangle {
            id: rectHourMeter
            width: 135
            height: 40
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            border {
                color: color_gray_bar
                width: 1
            }
            visible: true

            Image {
                id: hourMeterIcon
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: rectHourMeter.left
                    leftMargin: 3
                }
                source: "qrc:/graphics/Header/7.1 Hourmeter - home page - white.png"
                fillMode: Image.Pad
            }

            Text {
                id: textHourMeter
                anchors {
                    verticalCenter: parent.verticalCenter
                    right: rectHourMeter.right
                    rightMargin: 8
                }
                text: hourMeter + "h"
                font.pixelSize: 28
                font.family: systemFont
                clip: true
                color: color_white
            }
        }
    }
}
