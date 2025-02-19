import QtQuick 2.0
import MyQmlModule 1.0

Rectangle {
    id: workStartContainer

    width: parent.width
    height: 75
    color: parent.color

    property int index: 1               // index of this level

    property string amPm : "AM"
    property string amPm_heat : "AM"

    property int totalMinutes: 0
    property int heatStartMinutes: 0
    property int workStartMinutes: 0

    property bool is12HourFormat: dm.getFormatHour() === 1 ? true : false


    function selectWorkHOur(value) {
        workHourContainer.isCurrent = value
    }

    function increaseWorkHour() {
        if(is12HourFormat)
        {
            workHourContainer.currentNumber = (workHourContainer.currentNumber + 1) % 12
            if (workHourContainer.currentNumber === 0) {
                workHourContainer.currentNumber = 12
            }

            if (workHourContainer.currentNumber === 12 && amPm === "AM") {
                amPm = "PM"
            } else if (workHourContainer.currentNumber === 12 && amPm === "PM") {
                amPm = "AM"
            }
        } else
        {
            workHourContainer.currentNumber = (workHourContainer.currentNumber + 1) % 24
        }
    }

    function decreaseWorkHour() {
        if(is12HourFormat)
        {
            workHourContainer.currentNumber = (workHourContainer.currentNumber - 1 + 12) % 12
            if (workHourContainer.currentNumber === 0) {
                workHourContainer.currentNumber = 12
            }

            if (workHourContainer.currentNumber === 11 && amPm === "AM") {
                amPm = "PM"
            } else if (workHourContainer.currentNumber === 11 && amPm === "PM") {
                amPm = "AM"
            }
        } else
        {
            workHourContainer.currentNumber = (workHourContainer.currentNumber - 1 + 24) % 24
        }
    }

    function selectWorkMin(value) {
        workMinContainer.isCurrent = value
    }

    function increaseWorkMin() {
        workMinContainer.currentNumber = (workMinContainer.currentNumber + 1) % 60
    }

    function decreaseWorkMin() {
        workMinContainer.currentNumber = (workMinContainer.currentNumber - 1 + 60) % 60
    }

    function validateWorkTime() {
        var workHours_screen = workHourContainer.currentNumber
        var workMins_screen = workMinContainer.currentNumber

        var heatHours_screen = 0
        var heatMins_screen = 0

        if (is12HourFormat) {
            totalMinutes = workHours_screen * 60 + workMins_screen
            heatStartMinutes = (totalMinutes - 30 + 12 * 60) % (12 * 60)

            heatHours_screen = Math.floor(heatStartMinutes / 60)
            heatMins_screen = heatStartMinutes % 60

            if (workHours_screen === 12 && amPm === "AM") {
                // Special case for midnight
                if (heatHours_screen === 11) {
                    amPm_heat = "PM"
                } else {
                    amPm_heat = "AM"
                }
            } else if (workHours_screen === 12 && amPm === "PM") {
                // Special case for 12 PM
                if (heatHours_screen === 11) {
                    amPm_heat = "AM"
                } else {
                    amPm_heat = "PM"
                }
            } else {
                amPm_heat = amPm
            }

            if (heatHours_screen === 0) {
                heatHours_screen = 12
            }
        }

        else {
            totalMinutes = (workHours_screen * 60 + workMins_screen - 30 + 24 * 60) % (24 * 60)
            heatStartMinutes = totalMinutes
            heatHours_screen = Math.floor(heatStartMinutes / 60)
            heatMins_screen = heatStartMinutes % 60
        }

        heatHourContainer.currentNumber = heatHours_screen
        heatMinContainer.currentNumber = heatMins_screen

        var heatHours_result = heatHours_screen
        var heatMins_result = heatMins_screen

        if (is12HourFormat) {
            if (heatHours_result !== 12 && amPm_heat === "PM") {
                heatHours_result += 12
            }

            if (heatHours_result === 12) {
                if (amPm_heat === "AM") {
                    heatHours_result = 0
                }
            }
        }

        dm.getPreHeating().start_hours = heatHours_result
        dm.getPreHeating().start_minutes = heatMins_result

        confirmWorkTime()
    }

    function confirmWorkTime() {
        workHourContainer.confirmValue()
        workMinContainer.confirmValue()
        heatHourContainer.confirmValue()
        heatMinContainer.confirmValue()
    }

    function cancelWorkTime() {
        workHourContainer.cancelValue()
        workMinContainer.cancelValue()
        heatHourContainer.cancelValue()
        heatMinContainer.cancelValue()
    }

    function initializeHeatAndWorkTimes() {
        var heatHours = dm.getPreHeating().start_hours
        var heatMins = dm.getPreHeating().start_minutes

        totalMinutes = (heatHours * 60 + heatMins + 30 + 24 * 60) % (24 * 60)
        var workHours = Math.floor(totalMinutes / 60)
        var workMins = totalMinutes % 60

        if (is12HourFormat) {
            amPm_heat = heatHours >= 12 ? "PM" : "AM"
            if (heatHours === 11 && amPm_heat === "AM") {
                // Special case for midnight
                if (workHours === 12) {
                    amPm = "PM"
                } else {
                    amPm = "AM"
                }
            } else if (heatHours === 23 && amPm_heat === "PM") {
                // Special case for 12 PM
                if (workHours === 0) {
                    amPm = "AM"
                } else {
                    amPm = "PM"
                }
            } else {
                amPm = amPm_heat
            }

            var hourHeat = heatHours % 12
            if (hourHeat === 0) {
                hourHeat = 12
            }
            heatHours = hourHeat

            var hourWork = workHours % 12
            if (hourWork === 0) {
                hourWork = 12
            }
            workHours = hourWork
        }

        heatHourContainer.currentNumber = heatHours
        heatMinContainer.currentNumber = heatMins

        workHourContainer.currentNumber = workHours
        workMinContainer.currentNumber = workMins

        confirmWorkTime()
    }

    Rectangle {
        id: levelRect

        width: 0.45 * parent.width
        height: 30
        color: levelsController.isCurrentIndex === index && pg_preHeating.layerdIndex === 0 ? color_blue : color_gray
        border {
            color: levelsController.isCurrentIndex === index && pg_preHeating.layerdIndex === 0 ? color_blue : color_gray_bar
            width: 2
        }
        anchors {
            leftMargin: 5
            left: parent.left
            topMargin: 5
            top: parent.top
        }

        Text {
            id: selectionWorkStartText
            color: color_white
            font.pixelSize: 14
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: qsTrId("LBL_0064") + translator.emptyString
        }
    }

    Comp_boxNumber {
        id: workHourContainer
        anchors {
            leftMargin: 10
            left: levelRect.right
            topMargin: 5
            top: parent.top
        }
        isArrows: true
    }

    Text {
        id: separatorText
        text: ":"
        color: color_white
        font.pixelSize: 20
        font.family: systemFont
        anchors {
            leftMargin: 1
            left: workHourContainer.right
            verticalCenter: workHourContainer.verticalCenter
        }
    }

    Comp_boxNumber {
        id: workMinContainer
        anchors {
            leftMargin: 1
            left: separatorText.right
            topMargin: 5
            top: parent.top
        }
        isArrows: true
    }

    Text {
        id: workFormatHourText
        text: is12HourFormat ? amPm : ""
        color: color_white
        font.pixelSize: 20
        font.family: systemFont
        anchors {
            leftMargin: 2
            left: workMinContainer.right
            verticalCenter: workMinContainer.verticalCenter
        }
    }

    Rectangle {
        id: levelRect2

        width: 0.45 * parent.width
        height: levelRect.height
        color: color_gray
        anchors {
            leftMargin: 5
            left: parent.left
            topMargin: 11
            top: levelRect.bottom
        }
        Text {
            id: selectionHeatStartText
            color: color_white
            font.pixelSize: 14
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: qsTrId("LBL_0065") + translator.emptyString
        }
    }

    Comp_boxNumber {
        id: heatHourContainer
        anchors {
            leftMargin: 10
            left: levelRect2.right
            topMargin: 11
            top: levelRect.bottom
        }
        isArrows: false
    }

    Text {
        id: separatorText2
        text: ":"
        color: color_white
        font.pixelSize: 20
        font.family: systemFont
        anchors {
            leftMargin: 1
            left: heatHourContainer.right
            verticalCenter: heatHourContainer.verticalCenter
            topMargin: 11
            top: levelRect.bottom
        }
    }

    Comp_boxNumber {
        id: heatMinContainer
        anchors {
            leftMargin: 1
            left: separatorText2.right
            topMargin: 11
            top: levelRect.bottom
        }
        isArrows: false
    }

    Text {
        id: heatFormatHourText
        text: is12HourFormat ? amPm_heat : ""
        color: color_white
        font.pixelSize: 20
        font.family: systemFont
        anchors {
            leftMargin: 2
            left: heatMinContainer.right
            verticalCenter: heatMinContainer.verticalCenter
        }
    }

}
